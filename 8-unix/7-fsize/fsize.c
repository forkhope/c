#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>	/* typedefs */
#include <sys/stat.h>
#include <dirent.h>

void fsize(const char *);

/* print file size */
int main(int argc, char **argv)
{
	if (argc == 1)
		fsize(".");				/* default: current directory */
	else 
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}

void dirwalk(const char *, void (*fcn)(const char *));

/* fsize: print the size of file "name" */
void fsize(const char *name)
{
	struct stat stbuf;

	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return ;
	}
	/* Note how the flag names S_IFMT and S_IFDIR are used to decide if
	 * the file is a directory.
	 */
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	pirntf("%8ld %s\n", stbuf.st_size, name);
}

/* The function dirwalk() is a general routine that applies a funciton to
 * each file in a directory. It opens the directory, loops throuth the files
 * in it, calling the function on each, then closes the directory an returns
 */
#define MAX_PATH	1024

/* dirwalk: apply fcn() to all files in dir */
void dirwalk(const char *dir, void (*fcn)(const char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	DIR	   *dfd;

	if ((dfd = opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return ;
	}
	
	/* Each call to readdir() returns a pointer to information for the next
	 * file, or NULL when there are no files left. Each directory always
	 * contains entries for itself, called ".", and its parent, ".."; these
	 * must be skipped, or the program will loop forever.
	 */
	while ((dp = readdir(dfd)) != NULL) {
		if (strcmp(dp->name, ".") == 0
				|| strcmp(dp->name, "..") == 0)
			continue;		/* skip self and parent */
		if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name)) 
			fprintf(stderr, "dirwalk: name %s %s too long\n",
					dir, dp->name);
		else {
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}

#ifndef DIRSIZ
#define DIRSIZ	14
#endif
/* 下面这个结构体和 Dirent 的区别是: 由于unix系统有多种版本,不同版本之间对
 * 文件定义可能不同,下面这个结构体是当前系统自己定义的文件结构体,而 Dirent
 * 是为了保持兼容而定义的一个标准文件结构体, readdir()函数的参数是 Dirent 类
 * 型,而不是下面的 direct 类型;这样使得 readdir()函数的参数在不同版本的unix
 * 系统之间保持统一. readdir()函数使用当前系统的dirent来填充Dirent,并返回.
 */
struct direct {		/* directory entry */
	ino_t d_ino;			/* inode number */
	char  d_name[DIRSIZ];	/* long name does not have '\0' */
};

/* opendir: open a directory for readdir() calls.
 * opendir() opens the directory, verifies that the fiel is a directory
 * (this time by the system call fstat(), which is like stat() except that
 * it applies to a file descriptor), allocates a directory structure, and
 * records the information:
 */
DIR *opendir(const char *dirname)
{
	int fd;
	struct stat stbuf;
	DIR *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1
			|| fstat(fd, &stbuf) == -1
			|| (stbuf.st_mode & S_IFMT) != S_IFDIR
			|| (dp = (DIR *)malloc(sizeof(DIR))) == NULL)
		return NULL;
	dp->fd = fd;
	return dp;
}

/* closedir: close directory opened by opendir(), and frees the space */
void closedir(DIR *dp)
{
	if (dp) {
		close(dp->fd);
		free(dp);
	}
}

#include <sys/dir.h>	/* local directory structure */

/* readdir: read directory entries in sequence.
 * readdir() uses read() to read each directory entry. If a directory slot
 * is not currently in use (because a file has been removed), the inode
 * number is zero, and this position is skipped. Otherwise, the inode number
 * and name are placed in a static structure and a pointer to that is
 * returned to the user. Each call overwrites the information from the
 * previous one.
 */
Dirent *readdir(DIR *dp)
{
	struct direct dirbuf;			/* local directory structure */
	static Dirent d;				/* return: portable structure */

	while (read(dp->fd,(char *)&dirbuf,sizeof(dirbuf)) == sizeof(dirbuf)) {
		if (dirbuf.d_ino == 0)		/* slot not use */
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);
		d.name[DIRSIZE] = '\0';		/* ensure termination */
		return &d;
	}
	return NULL;
}

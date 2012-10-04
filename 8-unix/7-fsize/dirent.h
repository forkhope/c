#ifndef L_DIRENT_H
#define L_DIRENT_H

#define NAME_MAX	14		/* longest filename components; */
							/* system-dependent */

typedef struct {			/* portable directory entry */
	long ino;				/* inode number */
	char name[NAME_MAX+1];	/* name + '\0' terminator */
} Dirent;					/* 一个Dirent结构体对应目录中的一个文件 */

typedef struct {			/* minimal DIR: no buffering, etc. */
	int fd;					/* file descriptor for the directory */
	Dirent d;				/* the directory entry */
} DIR;						/* 一个DIR结构体对应一个目录 */

DIR *opendir(const char *dirname);
Dirent *readdir(DIR *dfd);
void *closedir(DIR *dfd);

#endif	/* L_DIRENT_H */

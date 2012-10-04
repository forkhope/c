#include <stdio.h>		/* 包含 BUFSIZ 宏的定义 */
#include <fcntl.h>		/* 声明 open(), creat() 函数 */
#include <unistd.h>
#define PERMS	0666	/* RW for owner, group, others */

void error(const char *fmt, ...);

/* cp: copy f1 to f2 */
int main(int argc, char *argv[])
{
	int f1, f2, n;
	char buf[BUFSIZ];

	if (argc != 3)
		error("Usage: cp from to");

	/* Other than the default standard input, output and error, you must
	 * explicitly open files in order to read or write them. There are two
	 * system calls for this, open() and creat(). open() returns a file
	 * descriptor, which is just an int; it returns -1 if any error occurs.
	 */
	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
		error("cp: can't open %s", argv[1]);
	
	/* It is an error to try to open a file that does not exist. The system
	 * call creat() is provided to create new files, or to re-write old ones
	 * It returns a file descriptor if it was able to create the file, and 
	 * -1 if not. If the file already exist, creat() will truncate it to 
	 * zero length, thereby discarding its previous contents; it is not an
	 * error to creat() a file that already exists. If the file does not
	 * already exist, creat() creates it with the permissions specified by
	 * the second argument, 例如下面的 PERMS 宏就是新创建的文件权限.
	 */
	if ((f2 = creat(argv[2], PERMS)) == -1)
		error("cp: can't create %s, mode: %03o", argv[2], PERMS);
	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(f2, buf, n) != n)
			error("cp: write error on file %s", argv[2]);
	/* 对打开的文件操作完毕,及时将它们关闭是一个良好的习惯 */
	close(f1);
	close(f2);

	return 0;
}

#include <stdarg.h>
#include <stdlib.h>		/* 声明 exit() 函数 */

/* error: print an error message and die */
void error(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}

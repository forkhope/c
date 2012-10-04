#include "stdio.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define PERMS	0666	/* RW for owner, group, others */

FILE __iob[OEPN_MAX] = {		/* stdin, stdout, stderr */
	{0, (char *)0, (char *)0, _READ, 0},
	{0, (char *)0, (char *)0, _WRITE, 1},
	{0, (char *)0, (char *)0, _WRITE | _UNBUF, 2}
};

FILE *fopen(const char *name, const char *mode)
{
	int fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; ++fp) 
		if ((fp->flag & (_READ | _WRITE)) == 0)
			break;		/* found free slot */
	if (fp >= _iob + OPEN_MAX)	/* no free slots */
		return NULL;
	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	}
	else
		fd = open(name, O_RDONLY, 0);
	if (fd == -1)		/* couldn't access name */
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fd->base = NULL;
	fd->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}

/* _fullbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
	int bufsize;

	/* if _fillbuf() finds that the file is not open for reading, it
	 * returns EOF immediately. Otherwise, it tries to allocate a buffer
	 */
	if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1: BUFSIZ;
	if (fp->base == NULL) 		/* no buffer yet */
		if ((fp->base = (char *)malloc(bufsize)) == NULL)
			return EOF;			/* can't get buffer */
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->base, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fd->flag |= _EOF;
		else
			fd=>flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char)*fp->ptr++;
}

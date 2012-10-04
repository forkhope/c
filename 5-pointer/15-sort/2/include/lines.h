#ifndef LINES_H
#define LINES_H

extern int readlines(char *lineptr[], int maxlines,
		char linebuf[], int bufsize);
extern void writelines(char *lineptr[], int nlines);

#endif	/* LINES_H */

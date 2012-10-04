#include <stdio.h>

/* getchar() and putchar() can be defined in terms of getc, putc, stdin, 
 * and stdout as follows(为了防止重名,下面使用的是Getchar, Putchar):
 */
#define Getchar()	getc(stdin)
#define Putchar(c)	putc((c), stdout)

int main(void)
{
	int c;

	while ((c = Getchar()) != EOF)
		Putchar(c);
	return 0;
}

#include <stdio.h>

void minprintf(const char *fmt, ...);

/* The type va_list is used to declare a variable that will refer to each
 * argument in turn; in minprintf, this variable is called ap, for "argument
 * pointer". The macro va_start initializes ap to point to the first unnamed
 * argument. It must be called once before ap is used. There must be at
 * least one named argument; the final named argument is used by va_start 
 * to get started. Each call of va_arg returns one argument and steps ap to
 * the next; va_arg uses a type name to determine what type to return and 
 * how big a step to take. Finally, va_end does whatever cleanup is 
 * necessary. It must be called before the program returns.
 */
int main(void)
{
	int i = 80;
	double d = 80.5048;
	char *s = "tian xia you qing ren";

	minprintf("i = %d\n", i);
	minprintf("d = %f\n", d);
	minprintf("s = %s\n", s);
	minprintf("%i %% %c\n");

	return 0;
}

#include <stdarg.h>	/* va_list, va_start(), va_arg(), va_end() */

/* minprintf: minimal printf with variable argument list */
void minprintf(const char *fmt, ...)
{
	va_list ap;		/* points to each unnamed arg in turn */
	const char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);	/* make ap point to 1st unnamed arg */
	for (p = fmt; *p; ++p) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {		/* ++p 跳过 '%' */
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; ++sval)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);	/* clean up when done */
}

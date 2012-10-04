#include<stdio.h>

/* Write a program to copy its input to output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\. This makes tabs and 
 * backspaces visible in an unambiguous way.
 */
int main()
{
	int c, d;

	while((c = getchar()) != EOF) {
		d = 0;
		if (c == '\\') {
			putchar('\\');
			putchar('\\');
			d = 1;
		}
		if (c == '\t') {
			putchar('\\');
			putchar('t');
			d = 1;
		}
		if (c == '\b') {	
			/* 直接从键盘输入时,'\b'字符无法检测,因为该字符不会提交到缓冲区
			 * 解决方法是预先在一个文本中嵌入 backspace 字符,方法是:In vim,
			 * type Ctrl-V Ctrl-H(in linux) or Ctrl-Q Ctrl-H(in windows).
			 * You will see ^H, this is a backspace. Save the file as foo.
			 * Then type your_program < foo.这样就能看到\b字符.
			 */
			putchar('\\');
			putchar('b');
			d = 1;
		}
		if (d == 0) 
			putchar(c);
	}
	return 0;
}

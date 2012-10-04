#include <stdio.h>

extern void escape(char s[], const char t[]);
extern void unescape(char s[], const char t[]);

/* 测试 escape() 和 unescape() */
int main()
{
	char text1[50] = "Hello,\n\tWorld! Mistake was \"Extra 'e'\"!\n";
    char text2[51];

    printf("Original string:\n%s\n", text1);
	
    escape(text2, text1);
    printf("Escaped string:\n%s\n", text2);

    unescape(text1, text2);
    printf("Unescaped string:\n%s\n", text1);

    return 0;
}

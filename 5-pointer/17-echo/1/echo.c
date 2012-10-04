#include <stdio.h>

/* echo command-line arguments; lst version */
int main(int argc, char *argv[])
{
	int i;

	/* By convention, argv[0] is the name by which the program was invoked,
	 * so argc is at least 1. 命令行参数被传入main()函数时,是以字符串的形式
	 * 传入,例如执行 echo hello, world,则argv[0], argv[1], 和 argv[2] 分别是
	 * "echo", "hello,", 和 "world". 注意这一点.
	 */
	for (i = 1; i < argc; ++i)
		printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
	printf("\n");
	return 0;
}

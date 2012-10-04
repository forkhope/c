#include<stdio.h>

#define IN	1 	/* inside a word */
#define OUT	0	/* outside a word */

/* Print a histogram of the lengths of words in its input. 按照输入的不同
 * 单词长度打印一个直方图,横轴是单词长度值,纵轴是该长度的单词个数.
 */
int main()
{
	int c, i, length, drawsize, state;
	int num[11];		   // 该数组元素存放相应单词长度的单词个数

	length = drawsize = 0; // length存放单词长度,drawsize存放最大的单词个数
	for (i = 0; i < 11; ++i)
		num[i] = 0;

	state = OUT;
	while ((c = getchar()) != EOF) {
		// 获取单词长度,并存入对应的数组元素中
		if (c != ' ' && c != '\t' && c != '\n') {
			++length;
			state = IN;
		}
		else if (state == IN) {
			if (length < 11)
				++num[length - 1];
			else
				++num[10];
			length = 0;
			state = OUT;
		}
	}
	for (i = 0; i < 11; ++i) 
		if (num[i] > drawsize)
			drawsize = num[i];	// 将最大的单词个数存入 drawsize
	
	// 打印直方图
	putchar('\n');
	while (drawsize > 0) {
		printf("%3d |  ", drawsize);
		for (i = 0; i < 11; ++i) {
			if (num[i] >= drawsize)
				printf("*  ");
			else
				printf("   ");
		}
		putchar('\n');
		--drawsize;
	}
	printf("    +-----------------------------------------\n");
	printf("     ");
	for (i = 1; i < 11; ++i)
		printf("  %d", i);
	printf(" >10\n");
	return 0;
}

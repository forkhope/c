#include <stdio.h>
#include "libhash.h"
#include "lstring.h"

#define MAXWORD	1000	/* 获取的单词最大长度 */
#define IN 1			/* 这些宏没有什么用处,仅仅用来填充hash表 */
#define OUT 2
#define TIAN 3
#define XIA 4
#define YOU	5
#define QING 6
#define REN 7

/* 测试 hash 相关函数的使用 */
int main(void)
{
	char word[MAXWORD];	/* 存放读取的单词、或者字符 */
	char name[50], defn[MAXWORD];

	while (getword(word, MAXWORD) != EOF) {
		if (word[0] == '"')	/* 略过字符串常量 */
			while (getword(word, MAXWORD) != '"')
				;
		if (strCmp(word, "#define") == 0) {
			if (getword(word, MAXWORD) != '\n') 
				strCpy(name, word);
			if (getword(word, MAXWORD) == '\n')
				install(name, "");
			else {
				strCpy(defn, word);
				install(name, defn);
			}
		}
	}
	printf("---------- 获取到的hash表如下: ----------\n");
	hashprint();

	printf("------- 查找宏 IN, 得到的宏内容如下: -----\n");
	struct nlist *block = lookup("IN");
	if (block != NULL)
		printf("%s\n", block->defn);
	return 0;
}

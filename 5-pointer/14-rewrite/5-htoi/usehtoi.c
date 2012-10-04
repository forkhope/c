#include <stdio.h>

extern unsigned int htoi(const char *s);

/* 测试 htoi() 函数 */
int main()
{
	char *s[] = {
		"F00",
		"bar",
		"0100",
		"0x1",
		"0XA",
		"0X0C0BE",
		"abcdef",
		"123456",
		"0x123456",
		"deadbeef",
		"zog_c"
	};
	int i;
	unsigned int result;

	for (i = 0; i < 11; ++i) {
		result = htoi(s[i]);
		printf("Convert hex \"%s\" to integer is :%u\n", s[i], result);
	}
	return 0;
}

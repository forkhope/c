#include <stdio.h>

int main()
{
	double aTof(const char s[]);
	char *numbers[] = {"123.45e-6", "-1.2e-3", "1.2e2", "-1.2e3"};
	int i;

	for (i = 0; i < 4; ++i)
		printf("%.8f\n", aTof(numbers[i]));
	return 0;
}

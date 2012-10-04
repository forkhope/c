#include <stdio.h>
#include <string.h>
#include "token.h"

/* undcl: convert word descriptions to declarations */
int main(void)
{
	int type;
	char temp[MAXTOKEN];
	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			}
			else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			}
			else 
				printf("invalid input at %s\n", token);
		printf("\t%s\n", out);
	}
	return 0;
}

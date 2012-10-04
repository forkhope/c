#include <stdio.h>
#include <string.h>
#include "token.h"

/* undcl: convert word descriptions to declarations
 * Modify undcl so that it does not add redundant parentheses to 
 * declarations
 */
int main(void)
{
	int type, pretoken;
	char temp[MAXTOKEN];
	while (gettoken() != EOF) {
		strcpy(out, token);
		pretoken = tokentype;
		while ((type = gettoken()) != '\n') {
			if (type == PARENS)
				if (pretoken == '*') {
					sprintf(temp, "(%s)()", out);
					strcpy(out, temp);
				}
				else
					strcat(out, token);
			else if (type == BRACKETS) {
				if (pretoken == '*') {
					sprintf(temp, "(%s)[]", out);
					strcpy(out, temp);
				}
				else
					strcat(out, token);
			}
			else if (type == '*') {
				sprintf(temp, "*%s", out);
				strcpy(out, temp);
			}
			else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			}
			else 
				printf("invalid input at %s\n", token);
			pretoken = type;
		}
		printf("\t%s\n", out);
	}
	return 0;
}

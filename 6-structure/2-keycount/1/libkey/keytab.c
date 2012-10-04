struct key {
	char *word;
	int count;
} keytab[] = {
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"else", 0},
	{"for", 0},
	{"if", 0},
	{"int", 0},
	{"return", 0},
	{"struct", 0},
	{"unsigned", 0},
	{"void", 0},
	{"while", 0}
};

/* sizeof 操作符的用法是 sizeof object 或者 sizeof (type name). An object
 * can be a variable or array or structure. A type name can be the name of
 * a basic type like int or double, or a derived type like a structure or
 * a pointer. 例如int i;则 sizeof i、sizeof(i)、sizeof(int)都是合法的,但是
 * sizeof int 是错误的用法,编译器对对此报错.
 * A sizeof can not be used in a #if line, because the preprocessor does
 * not parse type names. But the expression in the #define is not evaluated
 * by the preprocessor, so the code here is legal.
 * #define NKEYS (sizeof keytab / sizeof (struct key))
 */
int nkeys = sizeof keytab / sizeof(keytab[0]);

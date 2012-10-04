#ifndef CALLIB_H
#define CALLIB_H

extern double a_to_f(const char s[]);
extern int getop(char s[]);
extern void push(double f);
extern double pop(void);
extern void print_top(void);
extern double duplicate_top(void);
extern void swap(void);
extern void clear_stack(void);

#endif /* CALLIB_H */

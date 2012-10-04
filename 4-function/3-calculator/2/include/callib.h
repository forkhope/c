#ifndef L_CALLIB_H
#define L_CALLIB_H

extern int getop(char s[]);
extern double aTof(const char s[]);
extern void push(const double f);
extern double pop(void);
extern void print_top(void);
extern double duplicate_top(void);
extern void swap(void);
extern void clear_stack(void);

#endif /* L_CALLIB_H */

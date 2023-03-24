// operations.h
#ifndef OPERATIONS_H
#define OPERATIONS_H

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);

extern int (*add_ptr)(int a, int b);
extern int (*sub_ptr)(int a, int b);
extern int (*mul_ptr)(int a, int b);
extern int (*div_ptr)(int a, int b);
extern int (*mod_ptr)(int a, int b);

#endif


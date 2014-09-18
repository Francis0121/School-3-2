#include <stdio.h>

extern void func_c();
void func_b() { puts("b.c"); func_c(); }

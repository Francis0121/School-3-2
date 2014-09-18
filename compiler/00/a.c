#include <stdio.h>

extern void func_b();
void func_a() { puts("a.c"); func_b(); }

int main(void)
{
	puts("Hello world!");
	func_a();
	return 0;
}

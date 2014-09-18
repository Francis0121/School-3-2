#include <stdio.h>

extern void func_b();
void func_a() { puts("a.c"); func_b(); }

main()
{
	puts("Hello world!");
	func_a();
}

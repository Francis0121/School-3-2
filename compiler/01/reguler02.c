/*
	a+b+c+d�� ����ϴ� ������ ����

    G = ({S, A, B, C}, {a, b, c, d}, P, S),
	P: S -> aA
	   A -> aA | bB
	   B -> bB | cC
	   C -> cC | d
*/
#include <stdio.h>

#define END '\n'

char ch;
int errflag = 0;

void error()
{
	if (!errflag){
		puts("FAIL");
		errflag = 1;
	}
}

// �͹̳� a�� �ν��ϴ� �Լ�
void pa()
{
	if (ch=='a')
		ch = getchar();
	else error();
}

// �͹̳� b, c, d�� �ν��ϴ� �Լ��� �͹̳� a�� �ν��ϴ� �Լ� pa()�� ������ ������� �ۼ�
// �͹̳� b�� �ν��ϴ� �Լ�
void pb()
{
	if (ch=='b')
		ch = getchar();
	else error();
}

// �͹̳� c�� �ν��ϴ� �Լ�
void pc()
{
	if (ch=='c')
		ch = getchar();
	else error();
}
// �͹̳� d�� �ν��ϴ� �Լ�
void pd()
{
	if (ch=='d')
		ch = getchar();
	else error();
}

void pB();
void pA()
{
	switch (ch) {
	case 'a':
		pa(); pA();
		break;
	case 'b':
		pb(); pB();
		break;
	default:
		error();
	}
}

void pC();
void pB()
{
	switch (ch) {
	case 'b':
		pb(); pB();
		break;
	case 'c':
		pc(); pC();
		break;
	default :
		error();
	}
}

void pC()
{
	switch (ch) {
	case 'c':
		pc(); pC();
		break;
	case 'd':
		pd();
		break;
	default:
		error();
	}
}

void pS()
{
	if (ch=='a') {
		pa(); pA();
	} else error();
}

void print_rules()
{
	puts("Production Rules:");
	puts("\tS --> aA");
	puts("\tA --> aA");
	puts("\tA --> bB");
	puts("\tB --> bB");
	puts("\tB --> cC");
	puts("\tC --> cC");
	puts("\tC --> d");
}

void main()
{
	print_rules();	// production rules
	printf("Input string(ex. aabbccd) = ");

	ch = getchar();	// input string: "aabbbccd"
	pS();
	if (!errflag && ch==END) puts("OK");
	else error();
}

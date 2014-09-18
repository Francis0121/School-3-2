/*
	LRS(Language Recognition System)

	�׽�Ʈ ��Ʈ�� : "abb$", "aaabbb$"

<�ǽ�> main()�� getchar() ��ſ� ��ü ��Ʈ���� �Ѳ����� ���ڹ迭�� �Է��Ͽ�
	ó���ϴ� ������� �� ���α׷��� �����Ͻÿ�.
<�ǽ�> ������ �ٸ� ������ ���� ����ν� ���α׷��� �ۼ��� ���ÿ�.
*/
/*
	Language Recognizer for the following CFG.

	G = ({S, A}, {a, b}, P, S)
		P: S --> aAb
		   A --> aS
		   A --> b
*/

#include <stdio.h>

char ch;
int errflag = 0;

/*
	Recognition-failed message.
*/
void error()
{
	if (!errflag) {
		puts("FAIL");
		errflag = 1;
	}
}

void pa()
{
	if (ch == 'a')
		ch = getchar();
	else error();
}

void pb()
{
	if (ch == 'b')
		ch = getchar();
	else error();
}

/*
	S --> aAb
*/
void pS()
{
	void pA();

	if (ch == 'a') {
		pa(); pA(); pb();
	} else error();
}

/*
	A --> aS
	A --> b
*/
void pA()
{
	switch (ch) {
	case 'a':
		pa(); pS();
		break;
	case 'b':
		pb();
		break;
	default:
		error();
	}
}

void main()
{
	puts("Production Rules:");
	puts("\tS --> aAb");
	puts("\tA --> aS");
	puts("\tA --> b");
	printf("$�� ������ �Է½�Ʈ�� : ");

	ch = getchar();
	pS();

	if (!errflag && (ch == '$' || ch == '\n')) puts("OK");
	else error();
}

///************************************************************************
//* 
//* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 3 �г�
//* �輺�� 20093267, �輼�� 20093268, ��ȫö 20093284
//*
//* '('�� ���� �ִ� �� ���θ� ����ϰ� '('�� ������ ')'�� ��������
//* '('�� ����� �����ϴ� ������ �ݺ��ϸ� �ش� ������ �ذ��� �� �ֽ��ϴ�.
//*
//* '('�� ���� ���θ� stack���� ����Ͽ��µ� �� ������ �̹����� Ȯ���Ͽ��� ���
//* '('�Ӹ� �ƴ϶� '{', '[' �� ���ؼ� ����� ������ �ִ��� ���θ� �Ǵ��ϴ� 
//* ������ �����Ͽ����ϴ�. 
//*
//* ���� '('�� ���� ������ stack�� �ش� '('�� push�Ͽ� �ΰ� ')'�� �������
//* pop�� �ϵ��� �����Ͽ���, ���� '('�������� �ʰ� pop�� �Ұ�� error�� �߻�
//* �ϵ��� algorithm�� �ۼ��Ͽ����ϴ�.
//*
//*************************************************************************/
//#include <stdio.h>
//#include <string.h>
//
//#define TRUE 1	
//#define FALSE 0
//
//#define STACK_POP_ERROR -1	// POP ERROR �߻��� ���� ���
//#define STACK_MAX_SIZE 52	// �������� �־��� '(', ')'�� �Է� ũ�Ⱑ 50�̱� ������ 52���־����ϴ�. 
//							// ������ ũ�⸸ �־��� ���� ������ '('�� 50�� �ݺ� �� ���� �ֱ� ������ stack size �� 52�� �Ͽ����ϴ�.
//
//// ~ stack ���� ������ push, pop ����� ��밡���ϵ��� ����
//char stack[STACK_MAX_SIZE] = {0};
//char top = 0;
//
///**
//* @param parenthesis '(' �� �Է� ����
//*/
//void push(char parenthesis){
//	if(top == STACK_MAX_SIZE){
//		return;
//	}
//	stack[top++] = parenthesis;
//}
//
///*
//* @return stack ���� ���� ��ġ ��
//*/
//char pop(){
//	if(top == 0){
//		return STACK_POP_ERROR;
//	}
//	return stack[--top];
//}
//
//// ~ main
//
//int main(void){
//	FILE *in;
//	int iTestCase;
//	char chTemp; // input.txt���� scan �޴� ����
//	int flag; // ��� ���� ������� flag
//
//	in = fopen("input.txt", "r");
//
//	fscanf(in, "%d", &iTestCase);
//	fscanf(in, "%c", &chTemp);
//	while(iTestCase--){
//		// ~ init variable
//		flag = TRUE;
//		top = 0;
//		memset(stack, 0, sizeof(char) * STACK_MAX_SIZE);
//
//		// ~ input scan and judge 
//		while(TRUE){
//			if(fscanf(in, "%c", &chTemp) == -1 || chTemp == 10){ // file�� \n�� �����ų� �������� ��� ����
//				break;
//			}
//
//			if(chTemp == '('){ // '('�� ���� ��� push
//				push(chTemp);
//			}else{
//				if(pop() == STACK_POP_ERROR){// ')'�� ��� pop() �� ���ÿ� error check
//					flag = FALSE; // pop error �ΰ�� �ùٸ��� ���� ��� ex) '())'
//					// ~ scan
//					while(TRUE){ // scan�� �����鼭 ���ÿ� üũ�ϱ� ������ �ش� ���� ��� scan
//						if(fscanf(in, "%c", &chTemp) == -1 || chTemp == 10){
//							break;
//						}
//					}
//					break; // while �� ����
//				}
//			}
//		}
//
//		if(top != 0){ // ��� scan�� �Ϸ���� stack���� top�� 0�̾����(�ƹ��͵� �׿����� �ʾƾ���.)
//			flag = FALSE;//���� �׿��ִٸ� �ùٸ��� ���� ��� ex)'((())'
//		}
//
//		// ~ output print
//		if(flag){
//			printf("YES\n");
//		}else{
//			printf("NO\n");
//		}
//	}
//
//	return 0;
//}

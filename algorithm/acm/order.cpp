///************************************************************************
//* 
//* 국민대학교 전자정보통신대학 컴퓨터공학부 3 학년
//* 2003267 김성근
//* 
//*************************************************************************/
//#include <stdio.h>
//#include <string.h>
//
//#define TRUE 1
//#define FALSE 0
//
//#define ORDER_MAX_SIZE 101
//#define OUTPUT_ERROR_MSG "IMPOSSIBLE"
//
//int rOrder[ORDER_MAX_SIZE] = {0};
//int sOrder[ORDER_MAX_SIZE] = {0};
//
//int main(void){
//	FILE *in;
//	int iTestCase, i;
//	int size, iTemp;
//	int flagResult = TRUE;
//
//	in = fopen("input.txt", "r");
//	fscanf(in, "%d", &iTestCase);
//	while(iTestCase--){
//		// ~ initial variable
//		memset(rOrder, 0, sizeof(int)*ORDER_MAX_SIZE);
//		memset(sOrder, 0, sizeof(int)*ORDER_MAX_SIZE);
//		fscanf(in, "%d", &size);
//		for(i=0; i<size; i++){
//			fscanf(in, "%d", &iTemp);
//			rOrder[i] = iTemp;
//			if(i < iTemp){
//				flagResult = FALSE;
//			}
//		}
//		
//		if(!flagResult){
//			printf("%s\n", OUTPUT_ERROR_MSG);
//			continue;
//		}
//
//		// ~ rOrder
//		for(i=0; i<size; i++){
//			printf("%d ", rOrder[i]);
//		}
//		printf("\n");
//		
//		// ~ sOrder
//		for(i=0; i<size; i++){
//			printf("%d ", rOrder[i]);
//		}
//		printf("\n");
//
//	}
//
//	return 0;
//}
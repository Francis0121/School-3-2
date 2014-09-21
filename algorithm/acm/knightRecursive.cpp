//#include <stdio.h>
//
//#define MATRIX_SIZE 14 // MATRIX���� ���Ұ����� ������ ���� �ѹ����� ó���ϱ� ���� ���� ������ �� �ִ� ��ǥ�� �� �����ϱ� ���� 14ĭ���� ����
//
//#define UNAVAILABLE 1 // �������� ���ϴ� ����
//#define AVAILABLE 0 // ���� ������ ����
//
//typedef struct point{ // x, y ��ǥ ������ ���� struct
//	int x;
//	int y;
//} Point;
//
//Point direction[8] = {	{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2} }; // 8���� Ž���� ���� ��ǥ
//
//int chess[MATRIX_SIZE][MATRIX_SIZE] = { UNAVAILABLE }; // Chess ���� ǥ���ϴ� �迭
//
///**
//* @param col 
//*		chess ���� ����
//* @param row
//*		chess ���� ���� 
//*/
//void print(int col, int row){
//	int i, j;
//	for(i=2; i<row; i++){
//		for(j=2; j<col; j++){
//			printf("%d ", chess[i][j]);
//		}
//		printf("\n");
//	}
//}
//
///**
//*	����Ʈ Ž���� ��������� �ϱ� ���� �Լ�
//*
//*	@pos
//*		x,y position ��ġ	
//*	@counter
//*		Path ����� ����
//*	@size
//*		col * row ���� ũ��
//*/
//int recursive(Point pos, int counter, int size){
//	int i;
//	Point next;
//	
//	if(counter == size) 
//		return 1;
//	
//	for(i=0; i<8; i++){
//		next.x = pos.x + direction[i].x;
//		next.y = pos.y + direction[i].y;
//		
//		if( chess[next.x][next.y] == AVAILABLE ){
//			chess[next.x][next.y] = counter+1;
//
//			if(recursive(next, counter+1, size))
//				return 1;
//			
//			chess[next.x][next.y] = AVAILABLE;
//		}
//	}
//	return 0;
//}
//
//int main(void){
//	FILE *in;
//	int iTestCase, i, j;
//	int col, row, size;
//	Point point;
//
//	in = fopen("input.txt", "r");
//	fscanf(in, "%d", &iTestCase);
//	while(iTestCase--){
//		// ~ init variable and scan from input.txt file
//		fscanf(in, "%d %d %d %d", &col, &row, &point.x, &point.y);
//		size = col * row;
//		col+=2, row+=2, point.x+=1, point.y+=1;
//		for(i=0; i<MATRIX_SIZE; i++){
//			for(j=0; j<MATRIX_SIZE; j++){
//				if( (j>=2 && j<col) && (i>=2 && i<row) ){
//					chess[i][j] = AVAILABLE;
//				}else{
//					chess[i][j] = UNAVAILABLE;
//				}
//			}
//		}
//		// ~ algorithm
//		chess[point.x][point.y] = UNAVAILABLE;
//
//		// ~ printf
//		if(recursive(point, 1, size)){
//			printf("1\n");
//			print(col, row);
//		}else{
//			printf("0\n");
//		}
//	}
//
//	return 0;
//}
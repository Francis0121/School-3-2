///************************************************************************
//* 
//* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 3 �г�
//* �輺�� 20093267
//*
//* ü���� ����� ���� ������ Recursive(�����) ������� Ǭ �����Դϴ�.
//* �ش� �������� ���ǹ��� �ܼ��� �ϱ����� �迭�� 8*8�� �迭�� �ƴ� 8�� ���� 
//* �����ϼ� �ִ� ���� 2�� �翷���Ʒ��� �� �����Ͽ� 12*12�迭�� ������
//* Ǯ�����ϴ�.
//*
//* ���� �迭�� 2���� �̿��ϴ� ���̾ƴ� �ϳ��� �迭�� ����Ͽ�
//* �ϳ��� �迭���� �̿밡���Ѱ����� 0���� �ΰ� 0�̿��� ���ڴ�
//* ��� �� �� ���� �������� �Ǵ��Ͽ� �ϳ��� �迭�� Path�� 
//* ����ϴ� ������� �ڵ带 �ۼ��Ͽ����ϴ�.
//*
//*************************************************************************/
//#include <stdio.h>
//
//#define MATRIX_SIZE 12 // MATRIX���� ���Ұ����� ������ ���� �ѹ����� ó���ϱ� ���� ���� ������ �� �ִ� ��ǥ�� �� �����ϱ� ���� 12ĭ���� ����
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
//* 8*8�迭�� ����ϴ� �Լ��Դϴ�.
//*
//* @param col 
//*		chess ���� ���� (col�� ���̴� +2�� �� ����)
//* @param row
//*		chess ���� ���� (row�� ���̴� +2�� �� ����)
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
//*	8���� ��͸� �����ϸ�, ���ٰ����Ұ�� return 1���ϰ� ������ �Ұ����ϴٸ� return 0�� �Ѵ�.
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
//		size = col * row; // ���� ������Ű������ �ִ�� �ü� �ִ� size ���
//		col+=2, row+=2, point.x+=1, point.y+=1;// 12 * 12 �迭�� �ϱ� ������ �Է� ���� ���� row�� col�� ���̸� 2�� ������Ű�� x,y��ǥ���� 1�� �������׽��ϴ�.
//		for(i=0; i<MATRIX_SIZE; i++){//Matrix�� �̿밡���Ѱ����� �̿�Ұ����Ѱ������� ������ �ʱ�ȭ �ϴ� �κ�
//			for(j=0; j<MATRIX_SIZE; j++){
//				if( (j>=2 && j<col) && (i>=2 && i<row) ){
//					chess[i][j] = AVAILABLE;
//				}else{
//					chess[i][j] = UNAVAILABLE;
//				}
//			}
//		}
//		// ~ algorithm
//		chess[point.x][point.y] = UNAVAILABLE; // ó�� �����ϴ� ��ǥ
//
//		// ~ printf
//		if(recursive(point, 1, size)){ // ����Լ��� ���� ����� ����
//			printf("1\n");
//			print(col, row);
//		}else{
//			printf("0\n");
//		}
//	}
//
//	return 0;
//}
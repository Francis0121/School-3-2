//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//#define MATRIX_SIZE 14 // MATRIX���� ���Ұ����� ������ ���� �ѹ����� ó���ϱ� ���� ���� ������ �� �ִ� ��ǥ�� �� �����ϱ� ���� 14ĭ���� ����
//
//#define UNAVAILABLE 1 // �������� ���ϴ� ����
//#define AVAILABLE 0 // ���� ������ ����
//
//typedef struct point{ // x, y ��ǥ ������ ���� struct
//	int x;
//	int y;
//	int d;
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
//int stack(Point pos, int size){
//	int counter = 1;
//	vector<Point> stack;
//
//	stack.push_back(pos);
//	chess[pos.x][pos.y] = counter;
//
//	while(stack.size() != 0){	
//		if(counter == size) 
//			return 1;
//
//		Point p = stack.back(); // Stack�� �ִ� ���� �����µ� �ش� ���� ���� ���⼺ ���� ��Ű�� �Ǵ�.
//		
//		if(p.d > 7){ // ������ 8 �̻��̶�� ���̻� ������ ����� �������� return
//			Point b = stack.back();
//			stack.pop_back(); // ����
//			chess[b.x][b.y] = AVAILABLE; // �̿밡���ϰ� ����
//			counter--;
//		
//			b = stack.back();
//			stack.pop_back();
//			b.d++;
//			stack.push_back(b);
//			continue; // ������ ���ư�
//		}
//
//		Point next; // ������ �ʾҴٸ� �ش� ��ġ���� Ž��
//		next.x = p.x + direction[p.d].x;
//		next.y = p.y + direction[p.d].y;
//		next.d = 0;
//
//		if( chess[next.x][next.y] == AVAILABLE ){// �����ϴٸ�
//			counter++;
//			chess[next.x][next.y] = counter; // ������Ű�� �ش���ġ ��ǥ ǥ��
//			stack.push_back(next); // ���� ��ġ ���ÿ� ����
//		}else{ // ���� �Ұ����̶��
//			stack.pop_back();
//			p.d++;
//			stack.push_back(p);
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
//		col+=2, row+=2, point.x+=1, point.y+=1, point.d = 0;
//		for(i=0; i<MATRIX_SIZE; i++){
//			for(j=0; j<MATRIX_SIZE; j++){
//				if( (j>=2 && j<col) && (i>=2 && i<row) ){
//					chess[i][j] = AVAILABLE;
//				}else{
//					chess[i][j] = UNAVAILABLE;
//				}
//			}
//		}
//		
//		// ~ printf
//		if(stack(point, size)){
//			printf("1\n");
//			print(col, row);
//		}else{
//			printf("0\n");
//		}
//	}
//
//	return 0;
//}
//#include <stdio.h>
//
//#define MATRIX_SIZE 14 // MATRIX에서 사용불가능한 구역을 조건 한번으로 처리하기 위해 말이 움직일 수 있는 좌표를 다 지정하기 위해 14칸으로 지정
//
//#define UNAVAILABLE 1 // 접근하지 못하는 공간
//#define AVAILABLE 0 // 접근 가능한 공간
//
//typedef struct point{ // x, y 좌표 저장을 위한 struct
//	int x;
//	int y;
//} Point;
//
//Point direction[8] = {	{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2} }; // 8방향 탐색을 위한 좌표
//
//int chess[MATRIX_SIZE][MATRIX_SIZE] = { UNAVAILABLE }; // Chess 판을 표현하는 배열
//
///**
//* @param col 
//*		chess 행의 길이
//* @param row
//*		chess 열의 길이 
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
//*	나이트 탐색을 재귀적으로 하기 위한 함수
//*
//*	@pos
//*		x,y position 위치	
//*	@counter
//*		Path 기록할 정수
//*	@size
//*		col * row 곱한 크기
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
//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//#define MATRIX_SIZE 14 // MATRIX에서 사용불가능한 구역을 조건 한번으로 처리하기 위해 말이 움직일 수 있는 좌표를 다 지정하기 위해 14칸으로 지정
//
//#define UNAVAILABLE 1 // 접근하지 못하는 공간
//#define AVAILABLE 0 // 접근 가능한 공간
//
//typedef struct point{ // x, y 좌표 저장을 위한 struct
//	int x;
//	int y;
//	int d;
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
//		Point p = stack.back(); // Stack에 있던 값을 가져온뒤 해당 값에 대해 방향성 증가 시키고 판단.
//		
//		if(p.d > 7){ // 방향이 8 이상이라면 더이상 접근할 방법이 없음으로 return
//			Point b = stack.back();
//			stack.pop_back(); // 제거
//			chess[b.x][b.y] = AVAILABLE; // 이용가능하게 변경
//			counter--;
//		
//			b = stack.back();
//			stack.pop_back();
//			b.d++;
//			stack.push_back(b);
//			continue; // 전으로 돌아감
//		}
//
//		Point next; // 끝나지 않았다면 해당 위치에서 탐색
//		next.x = p.x + direction[p.d].x;
//		next.y = p.y + direction[p.d].y;
//		next.d = 0;
//
//		if( chess[next.x][next.y] == AVAILABLE ){// 가능하다면
//			counter++;
//			chess[next.x][next.y] = counter; // 증가시키고 해당위치 좌표 표시
//			stack.push_back(next); // 지금 위치 스택에 증가
//		}else{ // 접근 불가능이라면
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
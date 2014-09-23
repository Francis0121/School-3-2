///************************************************************************
//* 
//* 국민대학교 전자정보통신대학 컴퓨터공학부 3 학년
//* 김성근 20093267
//*
//* 체스판 기사의 여행 문제를 Recursive(재귀적) 용법으로 푼 문제입니다.
//* 해당 문제에서 조건문을 단순히 하기위해 배열을 8*8의 배열이 아닌 8에 말이 
//* 움직일수 있는 공간 2를 양옆위아래에 더 적용하여 12*12배열로 문제를
//* 풀었습니다.
//*
//* 또한 배열을 2개를 이용하는 것이아닌 하나의 배열만 사용하여
//* 하나의 배열에서 이용가능한공간을 0으로 두고 0이외의 숫자는
//* 모두 갈 수 없는 공간으로 판단하여 하나의 배열에 Path를 
//* 기록하는 방식으로 코드를 작성하였습니다.
//*
//*************************************************************************/
//#include <stdio.h>
//
//#define MATRIX_SIZE 12 // MATRIX에서 사용불가능한 구역을 조건 한번으로 처리하기 위해 말이 움직일 수 있는 좌표를 다 지정하기 위해 12칸으로 지정
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
//* 8*8배열을 출력하는 함수입니다.
//*
//* @param col 
//*		chess 행의 길이 (col의 길이는 +2가 된 상태)
//* @param row
//*		chess 열의 길이 (row의 길이는 +2가 된 상태)
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
//*	8방향 재귀를 실행하며, 접근가능할경우 return 1을하고 접근이 불가능하다면 return 0를 한다.
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
//		size = col * row; // 값을 증가시키기전에 최대로 올수 있는 size 계산
//		col+=2, row+=2, point.x+=1, point.y+=1;// 12 * 12 배열로 하기 때문에 입력 받은 값의 row와 col의 길이를 2씩 증가시키며 x,y좌표또한 1씩 증가시켰습니다.
//		for(i=0; i<MATRIX_SIZE; i++){//Matrix를 이용가능한공간과 이용불가능한공간으로 나누어 초기화 하는 부분
//			for(j=0; j<MATRIX_SIZE; j++){
//				if( (j>=2 && j<col) && (i>=2 && i<row) ){
//					chess[i][j] = AVAILABLE;
//				}else{
//					chess[i][j] = UNAVAILABLE;
//				}
//			}
//		}
//		// ~ algorithm
//		chess[point.x][point.y] = UNAVAILABLE; // 처음 시작하는 좌표
//
//		// ~ printf
//		if(recursive(point, 1, size)){ // 재귀함수를 돌려 결과값 도출
//			printf("1\n");
//			print(col, row);
//		}else{
//			printf("0\n");
//		}
//	}
//
//	return 0;
//}
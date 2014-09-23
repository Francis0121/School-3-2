/************************************************************************
* 
* 국민대학교 전자정보통신대학 컴퓨터공학부 3 학년
* 김성근 20093267
*
* 체스판 기사의 여행 문제를 Stack을 사용하여 푼 문제입니다.
* 해당 문제에서 조건문을 단순히 하기위해 배열을 8*8의 배열이 아닌 8에 말이 
* 움직일수 있는 공간 2를 양옆위아래에 더 적용하여 12*12배열로 문제를
* 풀었습니다.
*
* 또한 배열을 2개를 이용하는 것이아닌 하나의 배열만 사용하여
* 하나의 배열에서 이용가능한공간을 0으로 두고 0이외의 숫자는
* 모두 갈 수 없는 공간으로 판단하여 하나의 배열에 Path를 
* 기록하는 방식으로 코드를 작성하였습니다.
*
****************************
* Problem Solution
* 
* 1. 처음 C++ standard library의 vector를 이용하여 push, pop 기능을이용하여
* 구현하였지만, 해당 stl을 사용할 경우 6 x 8 배열에 대한 것도 오랜 시간이 걸림.
*
* 2. 해당 stl을 사용하지 않고 stack에 대한 함수를 구현한뒤 해당 함수를 부르
* 도록 코드를 작성 -> Source Error
*
* 3. stack 또한 함수로 구현한것을 모두 제외하고, stack이 전역 변수로 접근가능
* 하게 구현하여 처음에 선언된 전역변수에 모두 접근하여 실행하도록 변경 -> Success
*
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 12 // MATRIX에서 사용불가능한 구역을 조건 한번으로 처리하기 위해 말이 움직일 수 있는 좌표를 다 지정하기 위해 14칸으로 지정

#define UNAVAILABLE 1 // 접근하지 못하는 공간
#define AVAILABLE 0 // 접근 가능한 공간

typedef struct point{ // x, y 좌표 저장을 위한 struct
	char x;
	char y;
	char c;
	char d;
} Point;

Point direction[8] = {	{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2} }; // 8방향 탐색을 위한 좌표
Point point_stack[66]; // point를 저장시킬 스택
int point_top = 0; // stack 위치를 가리키기 위한 top value
int chess[MATRIX_SIZE][MATRIX_SIZE] = { UNAVAILABLE }; // Chess 판을 표현하는 배열

int main(void){
	FILE *in;
	int iTestCase, i, j;
	int col, row, size, x, y, c;
	int resultFlag = false;

	in = fopen("input.txt", "r");
	fscanf(in, "%d", &iTestCase);
	while(iTestCase--){
		// ~ init variable and scan from input.txt file
		resultFlag = false;
		point_top = 0;

		fscanf(in, "%d %d %d %d", &col, &row, &x, &y);
		size = col * row;
		col+=2, row+=2, x+=1, y+=1;
		for(i=0; i<MATRIX_SIZE; i++){
			for(j=0; j<MATRIX_SIZE; j++){
				if( (j>=2 && j<col) && (i>=2 && i<row) ){
					chess[i][j] = AVAILABLE;
				}else{
					chess[i][j] = UNAVAILABLE;
				}
			}
		}
		// ~ 시작위치 지정 전역변수에 있는 값을 변경하지 않기 위해 직접 접근하여 할당
		chess[x][y] = 1;
		point_stack[point_top].x = x;
		point_stack[point_top].y = y;
		point_stack[point_top].d = 0;
		point_stack[point_top++].c = 1;

		while(true){
			// directrion이 8보다 크다면 해당 위치를 이용 가능하게 변경
			// 그 이후 top 위치 감소
			if(point_stack[point_top-1].d >= 8){ 
				chess[point_stack[point_top-1].x][point_stack[point_top-1].y] = AVAILABLE;
				point_top--; 

				// 만약 top이 0이게 되면 더이상 해볼 수 있는 경우의 수가 없음으로 종료
				if(point_top == 0){
					break;
				}

				// 그 이외의 경우에는 그전의 값에 대해 direction 증가
				point_stack[point_top-1].d+=1;
				continue;
			}
			// direction을 통해 x,y 위치 변경
			x = point_stack[point_top-1].x + direction[point_stack[point_top-1].d].x;
			y = point_stack[point_top-1].y + direction[point_stack[point_top-1].d].y;

			if(chess[x][y] == AVAILABLE){// 그 공간이 접근 가능한 경우라면
				// chess path 기록 및 해당 값 stack에 쌓음
				chess[x][y] = point_stack[point_top-1].c+1;
				c = point_stack[point_top-1].c+1;
				if(c == size){
					resultFlag = true;
					break;
				}
				point_stack[point_top].x = x;
				point_stack[point_top].y = y;
				point_stack[point_top].d = 0;
				point_stack[point_top++].c = c;
			}else{// 접근이 불가능하다면 direction 증가
				point_stack[point_top-1].d+=1;
			}
		}


		// ~ 해당 chess 판에 대한 출력 함수
		if(resultFlag){
			printf("1\n");
			for(i=2; i<row; i++){
				for(j=2; j<col; j++){
					printf("%d ", chess[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("0\n");
		}
	}

	return 0;
}
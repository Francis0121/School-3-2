/************************************************************************
* 
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 3 �г�
* �輺�� 20093267
*
* ü���� ����� ���� ������ Stack�� ����Ͽ� Ǭ �����Դϴ�.
* �ش� �������� ���ǹ��� �ܼ��� �ϱ����� �迭�� 8*8�� �迭�� �ƴ� 8�� ���� 
* �����ϼ� �ִ� ���� 2�� �翷���Ʒ��� �� �����Ͽ� 12*12�迭�� ������
* Ǯ�����ϴ�.
*
* ���� �迭�� 2���� �̿��ϴ� ���̾ƴ� �ϳ��� �迭�� ����Ͽ�
* �ϳ��� �迭���� �̿밡���Ѱ����� 0���� �ΰ� 0�̿��� ���ڴ�
* ��� �� �� ���� �������� �Ǵ��Ͽ� �ϳ��� �迭�� Path�� 
* ����ϴ� ������� �ڵ带 �ۼ��Ͽ����ϴ�.
*
****************************
* Problem Solution
* 
* 1. ó�� C++ standard library�� vector�� �̿��Ͽ� push, pop ������̿��Ͽ�
* �����Ͽ�����, �ش� stl�� ����� ��� 6 x 8 �迭�� ���� �͵� ���� �ð��� �ɸ�.
*
* 2. �ش� stl�� ������� �ʰ� stack�� ���� �Լ��� �����ѵ� �ش� �Լ��� �θ�
* ���� �ڵ带 �ۼ� -> Source Error
*
* 3. stack ���� �Լ��� �����Ѱ��� ��� �����ϰ�, stack�� ���� ������ ���ٰ���
* �ϰ� �����Ͽ� ó���� ����� ���������� ��� �����Ͽ� �����ϵ��� ���� -> Success
*
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 12 // MATRIX���� ���Ұ����� ������ ���� �ѹ����� ó���ϱ� ���� ���� ������ �� �ִ� ��ǥ�� �� �����ϱ� ���� 14ĭ���� ����

#define UNAVAILABLE 1 // �������� ���ϴ� ����
#define AVAILABLE 0 // ���� ������ ����

typedef struct point{ // x, y ��ǥ ������ ���� struct
	char x;
	char y;
	char c;
	char d;
} Point;

Point direction[8] = {	{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2} }; // 8���� Ž���� ���� ��ǥ
Point point_stack[66]; // point�� �����ų ����
int point_top = 0; // stack ��ġ�� ����Ű�� ���� top value
int chess[MATRIX_SIZE][MATRIX_SIZE] = { UNAVAILABLE }; // Chess ���� ǥ���ϴ� �迭

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
		// ~ ������ġ ���� ���������� �ִ� ���� �������� �ʱ� ���� ���� �����Ͽ� �Ҵ�
		chess[x][y] = 1;
		point_stack[point_top].x = x;
		point_stack[point_top].y = y;
		point_stack[point_top].d = 0;
		point_stack[point_top++].c = 1;

		while(true){
			// directrion�� 8���� ũ�ٸ� �ش� ��ġ�� �̿� �����ϰ� ����
			// �� ���� top ��ġ ����
			if(point_stack[point_top-1].d >= 8){ 
				chess[point_stack[point_top-1].x][point_stack[point_top-1].y] = AVAILABLE;
				point_top--; 

				// ���� top�� 0�̰� �Ǹ� ���̻� �غ� �� �ִ� ����� ���� �������� ����
				if(point_top == 0){
					break;
				}

				// �� �̿��� ��쿡�� ������ ���� ���� direction ����
				point_stack[point_top-1].d+=1;
				continue;
			}
			// direction�� ���� x,y ��ġ ����
			x = point_stack[point_top-1].x + direction[point_stack[point_top-1].d].x;
			y = point_stack[point_top-1].y + direction[point_stack[point_top-1].d].y;

			if(chess[x][y] == AVAILABLE){// �� ������ ���� ������ �����
				// chess path ��� �� �ش� �� stack�� ����
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
			}else{// ������ �Ұ����ϴٸ� direction ����
				point_stack[point_top-1].d+=1;
			}
		}


		// ~ �ش� chess �ǿ� ���� ��� �Լ�
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
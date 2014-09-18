//#include <stdio.h>
//#include <string.h>
//
//#define MAX_CHESS_SIZE 12
//#define MAX_STACK_SIZE 1000
//
//#define TRUE 1
//#define FALSE 0
//
//#define AVAILABLE -2
//#define UNAVAILABLE -1
//
//int chess[MAX_CHESS_SIZE][MAX_CHESS_SIZE] = {0};
//
//int top = 0;
//int stack[MAX_STACK_SIZE] = {0};
//
//void push(int col, int row, int direction){
//	if(top > MAX_STACK_SIZE){
//		printf("Push error\n");
//		return;
//	}
//	stack[top++] = col;
//	stack[top++] = row;
//	stack[top++] = direction;
//}
//
//void pop(int *col, int *row, int *direction){
//	if(top == 0){
//		printf("Pop error\n");
//		return;
//	}
//	*direction = stack[--top];
//	*row = stack[--top];
//	*col = stack[--top];
//}
//
//void top_value(int *col, int *row, int *direction){
//	if(top == 0){
//		printf("Top error\n");
//		return;
//	}
//	*direction = stack[top-1];
//	*row = stack[top-2];
//	*col = stack[top-3];
//}
//
//void return_point(int *col, int *row, int *direction){
//	switch(*direction){
//	case 1:
//		*col-=2;
//		*row-=1;
//		break;
//	case 2:
//		*col-=1;
//		*row+=2;
//		break;
//	case 3:
//		*col-=2;
//		*row+=1;
//		break;
//	case 4:
//
//		*col-=1;
//		*row-=2;
//		break;
//	case 5:
//		*col+=2;
//		*row+=1;
//		break;
//	case 6:
//		*col+=1;
//		*row-=2;
//		break;
//	case 7:
//		*col+=2;
//		*row-=1;
//		break;
//	case 8:
//		
//		break;
//	}
//}
//
//int main(void){
//	FILE *in, *out;
//	int iTestCase;
//	int col, row, direction, colSize, rowSize, startCol, startRow;
//	int visitCount = 1;
//
//	in = fopen("input.txt", "r");
//	out = fopen("output.txt", "w");
//	fscanf(in, "%d", &iTestCase);
//	
//	while(iTestCase--){
//		visitCount = 0;
//		top = 0;
//		fscanf(in, "%d %d %d %d", &colSize, &rowSize, &startCol, &startRow);
//		
//		// ~ initial Matrix
//		for(col=0; col<MAX_CHESS_SIZE; col++){
//			for(row=0; row<MAX_CHESS_SIZE; row++){
//				if( (col >= 2 && col <= colSize+1) && (row >= 2 && row <= rowSize+1) ){
//					chess[col][row] = AVAILABLE;
//				}else{
//					chess[col][row] = UNAVAILABLE;
//				}
//			}
//		}
//		
//		startCol+=1;
//		startRow+=1;
//		direction = 1;
//		chess[startCol][startRow] = ++visitCount;
//		push(startCol, startRow, direction);
//		while(top != 0){
//			top_value(&col, &row, &direction);
//			while(direction < 9){
//				return_point(&col, &row, &direction);
//				if(chess[col][row] == AVAILABLE){
//					chess[col][row] = ++visitCount;
//					direction = 1;
//					push(col, row, direction);
//					//printf("[%d, %d] : %d\n", col, row, direction);
//					//fprintf(out, "[%d, %d] : %d\n", col-1, row-1, direction);
//					//fprintf(out, "Push : vc [%d]\n", visitCount);
//					break;
//				}else{
//					pop(&col, &row, &direction);
//					direction++;
//					push(col, row, direction);
//				}
//			}
//
//			if(direction == 9){
//				if(chess[col][row] == 1){
//					break;
//				}
//
//				//printf("Pop\n");
//				//fprintf(out, "[%d, %d] : %d\n", col-1, row-1, direction);
//				//fprintf(out, "Pop : vc [%d] \n", visitCount);
//
//				pop(&col, &row, &direction);
//				chess[col][row] = AVAILABLE;
//				visitCount--;
//
//				pop(&col, &row, &direction);
//				direction++;
//				push(col, row, direction);
//			}
//
//			if(colSize*rowSize == visitCount){
//				break;
//			}
//
//			//for(col=2; col<colSize+2; col++){
//			//	for(row=2; row<rowSize+2; row++){
//			//		//printf("%d ", chess[col][row]);
//			//		fprintf(out, "%d ", chess[col][row]);
//			//	}
//			//	//printf("\n");
//			//	fprintf(out, "\n");
//			//}
//			////printf("\n\n");
//			//fprintf(out, "\n\n");
//		}
//		
//		if(colSize*rowSize == visitCount){
//			printf("1\n");
//			for(col=2; col<colSize+2; col++){
//				for(row=2; row<rowSize+2; row++){
//					printf("%d ", chess[col][row]);
//				}
//				printf("\n");
//			}
//		}else{
//			printf("0\n");
//		}
//	}
//
//	return 0;
//}
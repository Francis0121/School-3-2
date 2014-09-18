//#include <stdio.h>
//#include <string.h>
//#include <vector>
//#include <algorithm>
//
//#define MAX_ROOM_SIZE 102
//#define QUEUE_SIZE 100404
//
//#define TRUE 1
//#define FALSE 0
//
//using namespace std;
//
//char room[MAX_ROOM_SIZE][MAX_ROOM_SIZE] = {0};
//
//int front = 0, rear = 0;
//int queue[QUEUE_SIZE] = {0};
//
//void enqueue(int col, int row){
//	if(rear > QUEUE_SIZE){
//		printf("Enqueue Error\n %d", rear);
//		return;
//	}
//	queue[rear++] = col;
//	queue[rear++] = row;
//}
//
//void dequeue(int *col, int *row){
//	if(front == rear){
//		printf("Error!\n");
//		return;
//	}
//	*col = queue[front++];
//	*row = queue[front++];
//}
//
//bool desc (int i,int j) { return (i>j); }
//
//int main(void){
//	FILE *in;
//	int iTestCase, chTemp, i;
//	int rowSize, colSize, row, col;
//	int calRow, calCol;
//	
//	int roomCount, sizeCount;
//	vector<int> vecRoomSize;
//
//	in = fopen("input.txt", "r");
//	fscanf(in, "%d", &iTestCase);
//	while(iTestCase--){
//		// ~ initial variable
//		vecRoomSize.clear();
//		roomCount = 0;
//
//		memset(room, 0, sizeof(char)*MAX_ROOM_SIZE*MAX_ROOM_SIZE);
//		fscanf(in, "%d %d", &rowSize, &colSize);
//		fscanf(in, "%c", &chTemp); // Enter
//		for(col=1; col<=colSize; col++){
//			for(row=1; row<=rowSize; row++){
//				fscanf(in, "%c", &chTemp);
//				room[col][row] = chTemp;
//			}
//			fscanf(in, "%c", &chTemp); // Enter
//		}		
//
//		for(col=1; col<=colSize; col++){
//			for(row=1; row<=rowSize; row++){
//				front = 0, rear = 0;
//				chTemp = room[col][row];
//				if(chTemp != '+' && chTemp != '.'){
//					continue;
//				}
//				
//				if(chTemp == '+'){
//					room[col][row] = 0;
//					continue;
//				}
//
//				
//				sizeCount=1;
//				roomCount++;
//				enqueue(col, row);
//				room[col][row] = roomCount;
//				while(front != rear){
//					dequeue(&calCol, &calRow);
//					// ~ South
//					if(room[calCol-1][calRow] == '.'){
//						enqueue(calCol-1, calRow);
//						room[calCol-1][calRow] = roomCount;
//						sizeCount+=1;
//					}
//					// ~ North
//					if(room[calCol+1][calRow] == '.'){
//						enqueue(calCol+1, calRow);
//						room[calCol+1][calRow] = roomCount;
//						sizeCount+=1;
//					}
//					// ~ East
//					if(room[calCol][calRow+1] == '.'){
//						enqueue(calCol, calRow+1);
//						room[calCol][calRow+1] = roomCount;
//						sizeCount+=1;
//					}
//					// ~ West
//					if(room[calCol][calRow-1] == '.'){
//						enqueue(calCol, calRow-1);
//						room[calCol][calRow-1] = roomCount;
//						sizeCount+=1;
//					}
//				}
//				vecRoomSize.push_back(sizeCount);
//			}
//		}
//		sort(vecRoomSize.begin(), vecRoomSize.end(), desc);
//
//		printf("%d\n", roomCount);
//		for(i=0; i<vecRoomSize.size(); i++){
//			printf("%d ", vecRoomSize[i]);
//		}
//		printf("\n");
//
//		// ~ print 
//		/*printf("%d %d\n", rowSize, colSize);
//		for(col=1; col<=colSize; col++){
//			for(row=1; row<=rowSize; row++){
//				printf("%d", room[col][row]);
//			}
//			printf("\n");
//		}*/
//	}
//
//	return 0;
//}
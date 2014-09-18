//#include "KnightTour.h"
//
//static int direction[8][2] = {
//	{1, -2}, {2, -1}, {2, 1}, {1, 2},
//	{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}		
//};
//
//KnightTour::KnightTour(){
//	sizeRow = sizeCol = 8; // default size of Chessboard
//}
//
//KnightTour::KnightTour(int sRow, int sCol){
//	if (sRow>=2 && sRow<=MAX_SIZE)
//		sizeRow = sRow;
//	else
//		sizeRow = 8; // set to default size
//	
//	if (sCol>=2 && sCol<=MAX_SIZE)
//		sizeCol = sCol;
//	else
//		sizeCol = 8; // set to default size
//}
//
//void KnightTour::printBoard(){
//	for (int r = 0; r < sizeRow; r++){
//		for (int c = 0; c < sizeCol; c++)
//			cout << board[r][c] << " ";
//		cout <<endl;
//	} // for r
//}
//
//bool KnightTour::buildKnightTour(int startRow, int startCol){
//	for (int r=0; r<sizeRow; r++)
//		for (int c=0; c<sizeCol; c++)
//			board[r][c]= 0;
//	
//	if (startRow <= 0 || startRow > sizeRow)
//		startRow = 0;
//	if (startCol <= 0 || startCol > sizeCol)
//		startCol = 0;
//	
//	board[startRow-1][startCol-1] = 1;
//	
//	return recurKnightTour(startRow-1, startCol-1, 1);
//}
//
//bool KnightTour::recurKnightTour(int row, int col, int move){
////	printf("Row : %d, Col : %d, Move : %d\n", row, col, move);
//	bool ret = true;
//	int nextRow, nextCol;
//	board[row][col] = move;
//
//	if (move == sizeRow*sizeCol){
//		ret = true;
//	}else{
//		for(int dir=0; dir<8; dir++){
//			nextRow = row + direction[dir][0];
//			nextCol = col + direction[dir][1];
//		
//			if(isValidMove(nextRow, nextCol)){
//				if(recurKnightTour(nextRow, nextCol, move+1)){
//					break;
//				}
//			}
//		}
//		ret = false;
//		board[row][col] = 0;
//	}
//	return ret;
//}
//
//bool KnightTour::isValidMove(int row, int col){
//	if(row>=sizeRow || row<0)
//		return false;
//	if(col>=sizeCol || col<0)
//		return false;
//	if(board[row][col] != 0)
//		return false;
//	else
//		return true;
//}
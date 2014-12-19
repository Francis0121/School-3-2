#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define FILE_NAME "word2.txt"

int colSize = 0, rowSize = 0;

/**
*	Read "dict.txt" File
*	
*	@param dictionary 파일을 읽어서 vector에 전부 넣는다.
*		type : vector<string> 
*/
void makeDictionary(vector<string> &dic){
	string line;
	ifstream myfile(FILE_NAME);

	if(myfile.is_open()){
		while(myfile.good()){
			getline(myfile, line);
			transform(line.begin(), line.end(), line.begin(), ::toupper); // 사전을 대문자로 변경
			dic.push_back(line);
		}
	}else{ 
		cout << "파일을 읽을수 없습니다."; 
	}

	myfile.close();
}

/**
*	Crossword puzzle input.txt 파일로 부터 읽어서 만들기
*
*	@param board 
*		type - vector<vector<string>>
*	@param order
*		type - vector<vectore<int>>
*	@param numCols
*		type - vector<int>
*	@param numRows
*		type - vector<int>
*/
void makeBoard(vector<vector<string>> &board, vector<vector<int>> &order, vector<int> numCols, vector<int> numRows){	
	// ~ Order
	vector<int> rowOrder;
	int inOrder;
	for(int col=0; col<colSize; col++){
		for(int row=0; row<rowSize; row++){
			cin >> inOrder;	
			rowOrder.push_back(inOrder);
		}
		order.push_back(rowOrder);
		rowOrder.clear();
	}
	// ~ Board
	vector<string> rows; 
	string str;
	for(int col=0; col<colSize; col++){
		cin >> str;
		for(int row=0; row<rowSize; row++){
			string ch;
			ch.push_back(str.at(row));
			rows.push_back(ch);
		}
		board.push_back(rows);
		rows.clear();
	}
	// ~ number
	int size, num;
	// ~ across
	cin >> size;
	for(int i=0; i<size; i++){
		cin >> num;
		numCols.push_back(num);
	}
	// ~ down
	cin >> size;
	for(int i=0; i<size; i++){
		cin >> num;
		numRows.push_back(num);
	}
}

/**
*	Crossword puzzle 출력
*	@param board
*		type : vector<vector<string>>
*/
void printBoard(vector<vector<string>> board){

	for(int col=0; col<colSize; col++){
		for(int row=0; row<rowSize; row++){
			cout << board[col][row];
		}
		cout << endl;
	}
}

/**
*	"?" 빈칸이라면
*/
bool isEmpty(vector<vector<string>> board, vector<int> v){

	// ~ 수평에 있는 경우
	if(v[2] == 1){
       for(int i = 0; i < v[3]; i++){
            if (board[v[0]][i+v[1]] == "?")
                return true;
	   }
    }

	// ~ 수직에 있는 경우
    if(v[2] == -1){
       for(int i = 0; i < v[3]; i++){
            if (board[i+v[0]][v[1]] == "?")
                return true;
	   }
    }

    return false;
}

/**
*	수평적 수직적인 cross word 라인을 찾는다
*/
vector<int> findLine(vector<vector<string>> board){

	for(int col=0; col<colSize; col++) {

		for (int row=0; row<rowSize; row++) {

			if (board[col][row] != "*") { 

				// ~ 수평적으로 slot 찾음
				for (int k=row; k<rowSize; k++) {
					if (board[col][k] == "*" || k == rowSize-1){
						vector<int> v;
						int l = k - row + 1;
						if (board[col][k] == "*") 
							l = k - row;
						
						if (l>1) {
							v.push_back(col);
							v.push_back(row);
							v.push_back(1);
							v.push_back(l);
							if (isEmpty(board, v))
							    return v;
						}
						break;
					}
				}

				// ~ 수직적으로 slot 찾음
				for (int k=col; k<colSize; k++) {
					if ((board [k][row] == "*" ) || k == colSize-1){
						vector<int> v;
						int l = k - col + 1;
						if (board[k][row] == "*" ) l = k-col;
						if (l>1){
							v.push_back(col);
							v.push_back(row);
							v.push_back(-1);
							v.push_back(l);
							if (isEmpty(board, v))
							    return v;
						}
						break;
					}
				}
			}
		}
	}

	vector<int> v;

	v.push_back(-1);
	v.push_back(-1);
	v.push_back(-1);
	v.push_back(-1);

	return v;
}

/**
*	crowss word 판으로 부터 word를 얻어온다.
*/
string getWord(vector<vector<string>> board, vector<int> v){
    string word= "";
	// ~ 수평에 있는 경우
    if(v[2] == 1){ 
       for(int i = 0; i < v[3]; i++){
            word+=board[v[0]][i+v[1]];
	   }
    }

	// ~ 수직에 있는 경우
    if(v[2] == -1){
       for(int i = 0; i < v[3]; i++){
            word+=board[v[0]+i][v[1]];
	   }
    }
	//cout << "Get Word : " << word << endl;
    return word;
}

/**
*	사전에서 word에서 빈칸 포함되는 단어를 찾는다.
*/
vector<string> findWords(vector<string> dic, string s) {
	vector<string> list;

    for (int i=0; i<dic.size(); i++){
		int flag = true;
		if (dic[i].size() == s.size()){	
			for(int j=0; j<s.size(); j++){
				if (s[j] != dic[i][j] && s[j] != '?') {
					flag = false;
					break;
				}
			}

			if (flag){
				list.push_back(dic[i]);	
			}
		}
	}

	return list;
}

/**
*	빈칸이 하나라면?	
*
*	@param col
*		type - col 
*	@param row
*		type - int
*	@param direction 
*		type - int : 1 = Horizontal, -1 = Vertical
*	@param board
*		type - vector<vector<string>> : cross word board
*/
bool isOneBlank(int col, int row, int direction, vector<vector<string>> &board){
	int count=0;
	// ~ 수평적
	if(direction == 1) {
		for(int i=col-1; i>= 0; i--) {
			if(board[i][row][0] == '?')
				count++;
			if(board[i][row][0] == '*')
				break;
		}
		for(int i=col+1; i<colSize; i++) {
			if(board[i][row][0] == '?')
				count++;
			if(board[i][row][0] == '*')
				break;
		}
		if(count > 0) { 
			return false;
		}
	}
	// ~ 수직적
	if(direction==-1) {
		for(int i=row-1; i>=0; i--) {
			if(board[col][i][0] == '?')
				count++;
			if(board[col][i][0] == '*')
				break;
		}
		for(int i=row+1; i<rowSize; i++ ) {
			if(board[col][i][0] == '?')
				count++;
			if (board[col][i][0] == '*')
				break;
		}
		if(count > 0) {
			return false;
		}
	}
	return true;
}

/**
*	기존 사전에 만든 단어가 있는지 존재 여부 확인
*	@param
*		type string : 만든 단어
*	@param
*		type vector<string> : 원래 사전
*/
bool confirmDic(string s, vector<string> &dic){

	for(int i=0; i<dic.size(); i++){
		string temp;
		for(int j=0; j<s.size(); j++){
			temp.push_back(dic[i][j]);		
		}

		if(temp == s) {
			return true;
		}
	}
	return false;
}

/**
*	스트링 순서 재배열
*	@param
*		type - string : 받는 문자열
*	@return
*		type - string
*/
string strReverse(string s){
	string ans;
	for(int i=s.size()-1; i>=0; i--){
		ans.push_back(s[i]);
	}
	return ans;
}

/**
*	빈칸이 하나라면?	
*
*	@param col
*		type - col 
*	@param row
*		type - int
*	@param direction 
*		type - int : 1 = Horizontal, -1 = Vertical
*	@param board
*		type - vector<vector<string>> : cross word board
*	@param s
*		type - char
*	@param dic
*		type - vector<string> 
*/
bool strCheck(int col, int row, int direction, vector<vector<string>> &board, char s, vector<string> &dic){
	string word;
	string pre;
	// ~ 수평적
	if(direction==1) {
		for(int i=col-1; i>=0; i--) {
			if(board[i][row][0] != '*')
				pre.push_back(board[i][row][0]);
			else
				break;
		}
		word.push_back(s);
		for(int i=col+1; i<colSize; i++) {
			if(board[i][row][0] !='*')
				word.push_back(board[i][row][0]);
			else
				break;
		}
		word = strReverse(pre)+ word;
		// ~ 단어가 있는지 확인
		if(confirmDic(word, dic)) { 
			return true;
		}
	}

	// ~ 수직적
	if(direction==-1) {
		for(int i=row-1; i>=0; i--) {
			if(board[col][i][0] != '*')
				pre.push_back(board[col][i][0]);
			else
				break;
		}
		word.push_back(s);
		for(int i=row+1; i < rowSize; i++ ) {
			if(board[col][i][0] != '*')
				word.push_back(board[col][i][0]);
			else
				break;
		}
		word = strReverse(pre) + word;
		// ~ 단어가 있는지 확인
		if(confirmDic(word, dic)) { 
			return true;
		}
	}

	return false;
}

/**
*	Board
*/
int fillBoardFromWords(string s, vector<int> v, vector<vector<string>> &board, vector<string> dic) {
	// ~ 수평적
    if(v[2] == 1){
		for(int i=0; i<v[3]; i++) {
			if (board[v[0]][i+v[1]][0] == '?') {
				if (isOneBlank(v[0], v[1]+i, 1, board) )
					if (!strCheck(v[0], v[1]+i, 1, board, s[i], dic)) 
						return -1;
			}
            board[v[0]][i+v[1]] = s[i];
       }	
    }

	// ~ 수직적
    if(v[2] == -1){
		for(int i=0; i<v[3]; i++) {
			if (board[v[0]+i][v[1]][0] == '?'){
				if (isOneBlank(v[0]+i, v[1], -1, board) )
					if (!strCheck(v[0]+i, v[1], -1, board, s[i], dic)) 
						return -1;
			}
            board[i+v[0]][v[1]] = s[i];
		}
    }
	
	return 0;
}

/**
*	Cross word 풀기
*/
int solveCrossword(vector<vector<string>> &board, vector<string> dic) {

	vector<int> v = findLine(board);
	if (v[0] == -1 && v[1] == -1 && v[2] == -1 && v[3] == -1){
		//exit(1);
		return 2;
	}

    string word = getWord(board, v);
    vector<string> words = findWords(dic, word);

	while (!words.empty()) {

		//cout << "CURRENT_WORD >>>>>>>>>> " << words.back() << endl;

		if(fillBoardFromWords(words.back(), v, board, dic) == -1) {
			words.pop_back();
			//printBoard(board);
			continue;
		}
		else{
			//printBoard(board);
			words.pop_back();
		} 

		int flag = solveCrossword(board, dic);
		if(flag == 2){
			return 2;
		}
	}
	return 1;
}	

int main(){
	// ~ FILE_NAME 을 읽고 vector로 Dictionary 을 만든다.
	vector<string> dic;
	makeDictionary(dic); 								

	int numTestCase;
	cin >> numTestCase;

	// ~ cross word 알고리즘 시작
	vector<vector<int>> order;
	vector<vector<string>> board;
	vector<int> numCols, numRows;
	for(int i=0; i<numTestCase; i++){
		// ~ colSize, rowSize 는 전역변수
		cin >> colSize >> rowSize;						
		makeBoard(board, order, numCols, numRows);				
		if(solveCrossword(board, dic)){
			printBoard(board);
		}
		order.clear();
		board.clear();
		numCols.clear();
		numRows.clear();
	}

    return 0;
}

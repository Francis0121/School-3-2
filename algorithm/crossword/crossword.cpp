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
*	@param dictionary ������ �о vector�� ���� �ִ´�.
*		type : vector<string> 
*/
void makeDictionary(vector<string> &dic){
	string line;
	ifstream myfile(FILE_NAME);

	if(myfile.is_open()){
		while(myfile.good()){
			getline(myfile, line);
			transform(line.begin(), line.end(), line.begin(), ::toupper); // ������ �빮�ڷ� ����
			dic.push_back(line);
		}
	}else{ 
		cout << "������ ������ �����ϴ�."; 
	}

	myfile.close();
}

/**
*	Crossword puzzle input.txt ���Ϸ� ���� �о �����
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
*	Crossword puzzle ���
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
*	"?" ��ĭ�̶��
*/
bool isEmpty(vector<vector<string>> board, vector<int> v){

	// ~ ���� �ִ� ���
	if(v[2] == 1){
       for(int i = 0; i < v[3]; i++){
            if (board[v[0]][i+v[1]] == "?")
                return true;
	   }
    }

	// ~ ������ �ִ� ���
    if(v[2] == -1){
       for(int i = 0; i < v[3]; i++){
            if (board[i+v[0]][v[1]] == "?")
                return true;
	   }
    }

    return false;
}

/**
*	������ �������� cross word ������ ã�´�
*/
vector<int> findLine(vector<vector<string>> board){

	for(int col=0; col<colSize; col++) {

		for (int row=0; row<rowSize; row++) {

			if (board[col][row] != "*") { 

				// ~ ���������� slot ã��
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

				// ~ ���������� slot ã��
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
*	crowss word ������ ���� word�� ���´�.
*/
string getWord(vector<vector<string>> board, vector<int> v){
    string word= "";
	// ~ ���� �ִ� ���
    if(v[2] == 1){ 
       for(int i = 0; i < v[3]; i++){
            word+=board[v[0]][i+v[1]];
	   }
    }

	// ~ ������ �ִ� ���
    if(v[2] == -1){
       for(int i = 0; i < v[3]; i++){
            word+=board[v[0]+i][v[1]];
	   }
    }
	//cout << "Get Word : " << word << endl;
    return word;
}

/**
*	�������� word���� ��ĭ ���ԵǴ� �ܾ ã�´�.
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
*	��ĭ�� �ϳ����?	
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
	// ~ ������
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
	// ~ ������
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
*	���� ������ ���� �ܾ �ִ��� ���� ���� Ȯ��
*	@param
*		type string : ���� �ܾ�
*	@param
*		type vector<string> : ���� ����
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
*	��Ʈ�� ���� ��迭
*	@param
*		type - string : �޴� ���ڿ�
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
*	��ĭ�� �ϳ����?	
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
	// ~ ������
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
		// ~ �ܾ �ִ��� Ȯ��
		if(confirmDic(word, dic)) { 
			return true;
		}
	}

	// ~ ������
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
		// ~ �ܾ �ִ��� Ȯ��
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
	// ~ ������
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

	// ~ ������
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
*	Cross word Ǯ��
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
	// ~ FILE_NAME �� �а� vector�� Dictionary �� �����.
	vector<string> dic;
	makeDictionary(dic); 								

	int numTestCase;
	cin >> numTestCase;

	// ~ cross word �˰��� ����
	vector<vector<int>> order;
	vector<vector<string>> board;
	vector<int> numCols, numRows;
	for(int i=0; i<numTestCase; i++){
		// ~ colSize, rowSize �� ��������
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

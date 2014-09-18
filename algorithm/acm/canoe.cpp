/*****************************************************
*	
*	국민대학교 전자정보통신대학 컴퓨터공학부 3 학년
*	김성근 20093267, 김세훈 20093268, 나홍철 20093284
*
******************************************************/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define CLASS_MAX_SIZE 4

using namespace std;

/**
*	Read input.txt file and make vector from data
*	And sort vector variable	
*
*	@param in
*		main open file
*	@param clazz
*		return clazz
*	@param size
*		file scan size
*	@param quotient
*		number K / class size 
*/
void input(FILE *in, vector<int> &clazz, int size, int quotient){
	clazz.clear();
	int value;
	for(int i=0; i<size; i++){
		fscanf(in, "%d", &value);
		clazz.push_back(quotient-value);
	}
	sort(clazz.begin(), clazz.end());
}

void print_test(vector<int> &clazz){
	for(unsigned int i=0; i<clazz.size(); i++){
		printf("%d ",  clazz[i]);
	}
	printf("\n");
}

int main(void){
	FILE *in;
	vector<int> classA, classB, classC, classD;
	int iTestCase;
	int numK, size;

	in = fopen("input.txt", "r");
	fscanf(in, "%d", &iTestCase);
	while(iTestCase--){
		// ~ init variable & scan input.txt 
		fscanf(in, "%d %d", &numK, &size);
		int quotient = numK/CLASS_MAX_SIZE,
			remainder = numK%CLASS_MAX_SIZE;

		input(in, classA, size, quotient);
		input(in, classB, size, quotient);
		input(in, classC, size, quotient);
		input(in, classD, size, quotient);
		// ~ algorithm
		

		// ~ print
		print_test(classA);
		print_test(classB);
		print_test(classC);
		print_test(classD);
	}

	return 0;
}
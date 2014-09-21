///*****************************************************
//*	
//*	국민대학교 전자정보통신대학 컴퓨터공학부 3 학년
//*	김성근 20093267, 김세훈 20093268, 나홍철 20093284
//*
//******************************************************/
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//#include <vector>
//
//#define DIVIDE_NUMBER 2
//
//using namespace std;
//
///**
//*	Read input.txt file and make vector from data
//*	And sort vector variable	
//*
//*	@param in
//*		main open file
//*	@param clazz
//*		return clazz
//*	@param size
//*		file scan size
//*	@param quotient
//*		number K / class size 
//*/
//void input(FILE *in, vector<int> &clazz, int size){
//	clazz.clear();
//	int value;
//	for(int i=0; i<size; i++){
//		fscanf(in, "%d", &value);
//		clazz.push_back(value);
//	}
////	sort(clazz.begin(), clazz.end());
//	switch(1)
//		case 1:
//			break;
//}
//
//void sum(vector<int> &sum, vector<int> &classA, vector<int> classB, int size, int quotient){
//	sum.clear();
//	for(int i=0; i<size; i++){
//		for(int j=0; j<size; j++){
//			sum.push_back((classA[i]+classB[j])-quotient);
//		}
//	}
//	sum.erase(unique(sum.begin(), sum.end()), sum.end()); // ~ 중복제거
//	sort(sum.begin(), sum.end()); // ~ 정렬
//}
//
//int binarySearching(vector<int> list, int value){
//	int near = 0;
//	int imin = 0, imax = list.size()-1;
//	// continue searching while [imin,imax] is not empty
//	while (imax > imin){
//		// calculate the midpoint for roughly equal partition
//		int imid = (imax - imin) / 2 + imin;
//		if(list[imid] == value){// key found at index imid
//			return list[imid]; 
//		}// determine which subarray to search
//		else if (list[imid] < value){// change min index to search upper subarray
//			imin = imid + 1;
//			near = list[imid]; 
//		}
//		else {// change max index to search lower subarray
//			imax = imid - 1;
//			near = list[imid];
//		}
//    }
//	// key was not found
//	return near;
//}
//
//void print_test(vector<int> &clazz){
//	for(unsigned int i=0; i<clazz.size(); i++){
//		printf("%d ",  clazz[i]);
//	}
//	printf("\n");
//}
//
//int main(void){
//	FILE *in;
//	vector<int> classA, classB, classC, classD;
//	vector<int> sumA, sumB;
//	int iTestCase;
//	int numK, size;
//
//	in = fopen("input.txt", "r");
//	fscanf(in, "%d", &iTestCase);
//	while(iTestCase--){
//		// ~ init variable & scan input.txt 
//		fscanf(in, "%d %d", &numK, &size);
//		int quotient = numK / DIVIDE_NUMBER,
//			remainder = numK % DIVIDE_NUMBER;
//
//		input(in, classA, size);
//		input(in, classB, size);
//		sum(sumA, classA, classB, size, quotient);
//
//		input(in, classC, size);
//		input(in, classD, size);
//		sum(sumB, classC, classD, size, quotient);
//		
//		//print_test(sumA);
//		//print_test(sumB);
//		
//		// ~ algorithm
//		int min = 0x7FFFFFFF;
//		for(unsigned int i=0; i<sumA.size(); i++){
//			int near = binarySearching(sumB, -sumA[i]);
//			int temp = sumA[i]+near, abs = temp < 0 ? -temp : temp;
//			
//			if(temp == 0){
//				min = 0;
//				break;
//			}else{
//				int minAbs = min < 0 ? -min : min;
//				if(abs < minAbs){
//					min = temp;
//				}else if(abs == minAbs){
//					if(temp < 0){
//						min = temp;
//					}
//				}
//			}
//			//printf("i : %d,%d,%d || min : %d\n", i, sumA[i], near, min);
//		}
//		
//
//		// ~ print	
//		printf("%d\n", min+numK);
//		//printf("\n");
//	}
//
//	return 0;
//}
//#include <stdio.h>
//
//int gcd(int one, int two){
//	if(two == 0){
//		return one;
//	}else{
//		return gcd(two, one%two);
//	}
//}
//
//int main(void){
//	FILE *in;
//	int iTestCase; 
//	int numOne, numTwo;
//
//	in = fopen("input.txt", "r");
//	fscanf(in, "%d" , &iTestCase);
//	while(iTestCase--){
//		fscanf(in, "%d %d", &numOne, &numTwo);
//
//		printf("%d\n", gcd(numOne, numTwo));
//	}
//
//	return 0;
//}
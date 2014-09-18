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
//	int beforeSon, beforeMom, afterSon, afterMom;
//	int sumSon, sumMom;
//	int divSon, divMom, div;
//
//	in = fopen("input.txt", "r");
//	fscanf(in, "%d", &iTestCase);
//	
//	while(iTestCase--){
//		div = 1;
//		fscanf(in, "%d %d %d %d", &beforeSon, &beforeMom, &afterSon, &afterMom);
//
//		// ~ equal denominator 
//		if(beforeMom == afterMom){
//			sumSon = beforeSon + afterSon;
//			sumMom = beforeMom;
//		}else{
//			sumSon = (beforeMom * afterSon) +  (afterMom * beforeSon);
//			sumMom = beforeMom * afterMom;
//		}
//
//		// ~ irreducible fraction
//		div = gcd(sumMom, sumSon);	
//		
//		divSon = sumSon / div;
//		divMom = sumMom / div;
//
//		printf("%d %d\n", divSon, divMom);
//	}
//
//	return 0;
//}
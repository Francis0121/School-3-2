//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//#define SET_MAX_SIZE 1000000
//#define TRUE 1
//#define FALSE 0
//
//int main(void){
//	FILE *in;
//	int numTestCase; 
//	int size, numK, numTemp, i;
//	vector<int> vecSet;
//
//	in = fopen("input.txt", "r");
//	fscanf(in, "%d", &numTestCase);
//	
//	while(numTestCase--){
//		// ~ init 
//		vecSet.clear();
//		fscanf(in, "%d %d", &size, &numK);
//		
//		// ~ scanf
//		for(i=0; i < size; i++){
//			fscanf(in, "%d", &numTemp);
//			vecSet.push_back(numTemp);
//		}
//		
//		// ~ sorting
//		sort(vecSet.begin(), vecSet.end());
//
//		// ~ search
//		int lastIndex = size-1;
//		int interval = 0x7FFFFFFF;
//		int numOfPairs = 0;
//
//		for(i=1; i<size; i++){
//			int key = vecSet[lastIndex];
//			int destination = numK - key;	
//
//			// ~  Binary Search
//			int halfSize = lastIndex/2;
//			int halfPoint = lastIndex/2;
//
//			// ~ Decrease Last Index
//			lastIndex-=1;
//			printf("NumK : %d\t, Destination : %d\t lastIndex : %d\n", numK, destination, lastIndex);
//			while(halfSize){
//				int halfPointValue = vecSet[halfPoint];
//				int tempInterval = key + halfPointValue - numK;
//				tempInterval = tempInterval < 0 ? -tempInterval : tempInterval;
//				if(halfPointValue == destination){
//					if(interval == tempInterval){
//						numOfPairs++; 
//					}else{
//						interval = tempInterval;
//						numOfPairs = 1;
//					}
//					printf("Break Interval : [%d, %d]\t,\tValue : [%d, %d]\tSize : [%d, %d]\n", interval, tempInterval, key, halfPointValue, halfPoint, halfSize); 
//					break; 
//				}else if(halfPointValue < destination){
//					halfSize /= 2;
//					halfPoint += halfSize;
//					if(interval > tempInterval){
//						interval = tempInterval;
//						numOfPairs = 1;
//					}else if(interval == tempInterval){
//						numOfPairs++;
//					}else{
//						
//					}
//					printf("Plus Interval : [%d, %d]\t,\tValue : [%d, %d]\tSize : [%d, %d]\n", interval, tempInterval, key, halfPointValue, halfPoint, halfSize); 
//				}else{
//					halfSize /= 2;
//					halfPoint -= halfSize;
//					if(interval > tempInterval){
//						interval = tempInterval;
//						numOfPairs = 1;
//					}else if(interval == tempInterval){
//						numOfPairs++;
//					}else{
//
//					}
//					printf("Minus Interval : [%d, %d]\t,\tValue : [%d, %d]\tSize : [%d, %d]\n", interval, tempInterval, key, halfPointValue, halfPoint, halfSize); 
//				}
//			}
//			// ~ ?? 
//			if(halfSize == 0 && halfPoint == 1){
//				printf("Not Check zero Index\n");
//			}
//			if(halfSize == 0 && halfPoint == lastIndex-1){
//				printf("Not Check max Index\n");
//			}
//		}
//
//		printf("NumOfPairs : %d\t", numOfPairs);
//
//		for(unsigned j=0; j<vecSet.size(); j++){
//			printf("%d ", vecSet[j]);
//		}
//
//		printf("\n\n\n\n");
//	}
//		
//	return 0;
//}
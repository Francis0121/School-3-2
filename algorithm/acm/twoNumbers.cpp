//#include <stdio.h>
//#include <string.h>
//
//#define SIZE 200000001
//#define CENTER 100000000
//#define INT_MAX_VALUE 0x7FFFFFFF
//
//#define NOT_EXIST 0
//#define EXIST 1
//
//char arr[SIZE] = {0};
//int value[1000000] = {0};
//int curMin = INT_MAX_VALUE;
//
//int main(void){
//    
//    FILE *in;
//    int iTestNum = 0, i;
//    int count, temp, numK;
//    int standard, numOfPairs;
//  
//	in = fopen("input.txt", "r");
//    fscanf(in, "%d", &iTestNum);
//
//    while(iTestNum--){
//		// ~ Init variable		
//        curMin = INT_MAX_VALUE;
//        numOfPairs = 0;
//
//		// ~ scan input text
//		fscanf(in, "%d %d", &count, &numK);
//        for(i=0; i<count; i++){
//            fscanf(in, "%d", &temp);
//            if(temp > 0)
//				arr[CENTER+temp] = EXIST;
//            else if(temp < 0)
//				arr[CENTER+temp] = EXIST;
//            else
//				arr[CENTER] = EXIST;            
//            value[i] = temp;
//        }
//
//        for(i=0; i<count; i++){
//            standard = numK-value[i];
//            
//            temp = 0;
//			arr[CENTER+value[i]] = NOT_EXIST;
//
//            if(arr[CENTER] == 0 && value[i] == numK){
//                curMin = 0;
//                numOfPairs = 1;
//            }
//                
//            while(1)
//            {
//                if(curMin < temp)
//                    break;
//                if(arr[CENTER+standard] == 1)
//                {
//                    if(curMin == 0)
//                    numOfPairs++;
//                    else
//                    {
//                        curMin = 0;
//                        numOfPairs = 1;
//                    }
//                    break;
//                }
//                
//                
//                if(arr[CENTER+standard+temp] == 1)
//                {
//                    if(temp < curMin)
//                    {
//                        curMin = temp;
//                        numOfPairs = 1;
//                        if(arr[CENTER+standard-temp] == 1)
//                            numOfPairs++;
//                        break;
//                    }
//                    else if(temp == curMin)
//                    {
//                        numOfPairs++;
//                        if(arr[CENTER+standard-temp] == 1)
//                            numOfPairs++;
//                        break;
//                        
//                        
//                    }
//                    
//                    
//                }
//                else if(arr[CENTER+standard-temp] == 1)
//                {
//                    if(temp < curMin)
//                    {
//                        curMin = temp;
//                        numOfPairs = 1;
//                        
//                        if(arr[CENTER+standard+temp] == 1)
//                            numOfPairs++;
//                        break;
//                    }
//                    else if(temp == curMin)
//                    {
//                        numOfPairs++;
//                        if(arr[CENTER+standard+temp] == 1)
//                            numOfPairs++;
//                        break;
//                        
//                        
//                    }
//                    
//                    
//                }
//                temp++;
//                
//                
//            }
//        }
//        
//        printf("%d\n",numOfPairs);
//
//        
//        
//
//    }
//}
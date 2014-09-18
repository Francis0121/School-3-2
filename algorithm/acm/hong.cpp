//#include <stdio.h>
//
//int gcd(int a, int b);
//
//int main(void){
//   FILE *in;
//   int numTestCase;
//   int num1, num2;
//   int num1_1, num1_2, num2_1, num2_2;
//   int g;
//
//   in = fopen("input.txt", "r");
//   fscanf(in, "%d", &numTestCase);
//
//   while (numTestCase--){
//      fscanf(in, "%d %d %d %d", &num1_1, &num1_2, &num2_1, &num2_2);
//      
//      g = gcd(num1_2, num2_2);
//      num1 = (num1_1 * (num2_2 / g)) + (num2_1 * (num1_2 / g));
//      num2 = num1_2 / g  * num2_2;
//
//      g = gcd(num1, num2);
//
//      num1 /= g;
//      num2 /= g;
//      if (num1 == 0 || num2 == 0){
//         printf("%d %d\n", 0,0);
//      }
//      else{
//         printf("%d %d\n", num1, num2);
//      }
//   }
//   return 0;
//}
//
//
//int gcd(int a, int b){
//   if (b == 0)
//      return a;
//   return gcd(b, a%b);
//}
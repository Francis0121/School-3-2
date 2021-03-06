/***************************************************************************************
*
*           문제 : ACM_problemC(토로이드 그리드)
* 
*                국민대학교 전자정보통신대학 컴퓨터공학부 3 학년
*                김성근 20093267, 김세훈 20093268, 나홍철 20093284
*
*****************************************************************************************

1. 불가능한 경우는 없다.
2. 모든 입력값은 4가지 case로 나눌 수 있다.
  -홀수X홀수(m X n)
   (0,0)에서 시작하여 (0,1)->(1,1)->(1,2)->(0,2)->(0,3)...(0,n-1)까지 이동한뒤
   (m-1,n-1)로 이동하여 (m-1,n-2)->(m-1,n-3)...(m-1,0)까지 이동 후
   (m-2,0)으로 이동하여 (m-2,1)->(m-2,2)...(m-2,n-1)이런식으로 반복하여
   (1,0)에 도달한다.
 
  -홀수X짝수
   (0,0)에서 시작하여 (0,n-1)까지 이동 후
   (0,n-1)부터 (m-1,n-1)까지 이동 후
   (m-1,n-2)부터 (1,n-2)까지 이동 후
   (1,n-3)부터 (m-1,n-3)까지 이동 과정을 반복하여 
   (1,0)에 도달한다.
   
  -짝수X홀수
   (0,0)에서 시작하여 (0,n-1)까지 이동 후
   (m-1,n-1)부터 시작하여 (1,n-1)까지 이동 후
   (1,n-2)부터 시작하여 (m-1,n-2)까지 이동을 반복하여 
   (1,0)에 도달한다.
  -짝수X짝수
   홀수X짝수의 풀이법과 동일하다.
   
   */

#include <stdio.h>

int main(int argc, const char * argv[])
{    
    FILE *in;
    int numTestCases;
    int m,n;   // 토로이드 그리드의 행(m)과 열(n) 이다.
    int x,y;   // 검사하는 행(x)과 열(n) 이다.
    int i,j;
    in = fopen("input.txt","r");
    fscanf(in, "%d" ,&numTestCases);
    
    
    while (numTestCases--) {
        fscanf(in,"%d %d",&m,&n);
        x = y = 0;   // 검사 할 행과 열의 값을 초기화 해준다.

        printf("1\n");   // 불가능한 경우는 없으므로 
                  //정답이 있음을 알려주는 '1'을 출력한다.
   
      // CASE1 : 홀수X홀수 Toroidal Grid
        if(m%2 == 1 && n%2 == 1) 
        {
         /* (0,0)에서 시작하여 (0,1)->(1,1)->(1,2)->(0,2)->(0,3)...(0,n-1) 까지
         이동경로을 출력한다. */
            while (1)  { 
                printf("(%d,%d)\n",x,y);
             
                if (y % 2 == 0 && x % 2 == 0) y++;
                else if (y % 2 == 1 && x % 2 == 0) x++;
                else if (y % 2 == 1 && x % 2 == 1) y++;
                else if (y % 2 == 0 && x % 2 == 1) x--;
            
            /* (0,n-1)에 도착을 한다면 행과 열의 값을 출력하고 
            반복문을 나가 (m-1,n-1) 이동한다. */
                if (x == 0 && y == n-1)
                {
                    printf("(%d,%d)\n",x,y);
                    break;
                }
            }
            x = m-1; // 오른쪽 아래 
            y = n-1; // 모서리부터 탐색을 시작한다
            
         /* (m-1,n-1)로 이동하여 (m-1,n-2)->(m-1,n-3)...(m-1,0)까지 이동경로를 출력 후
          (m-2,0)으로 이동하여 (m-2,1)->(m-2,2)...(m-2,n-1)까지의 이동경로를 출력한다.
          이를 반복하여 (1,0)에 도달한다. */
            while(1)
            {
            printf("(%d,%d)\n",x,y);
            if(x == 1 && y == 0) break; // (1,0)에 도달 하면 종료한다.
                if(x % 2 == 0 && y != 0) y--;
                else if(x % 2 == 1 && y != n-1) y++;
                else if(y == 0 || y == n-1) x--;
            }
        }
      
      // CASE2 : 홀수X짝수 Toroidal Grid
        else if(m%2 == 1 && n%2 == 0) 
        {
         /* (0,0)에서 시작하여 (0,n-1)까지 이동경로를 출력한다.  */
            while (1) { 
                printf("(%d,%d)\n",x,y);
                y++;
                if(y == n-1) break;
            }
         /* (0,n-1)부터 (m-1,n-1)까지 이동경로를 출력한다. */
            while (1) { 
                printf("(%d,%d)\n",x,y);
                x++;
                if(x == m-1) break;
            }
         /* (m-1,n-2)부터 (1,n-2)까지 이동경로를 출력 후
         (1,n-3)부터 (m-1,n-3)까지 이동경로 출력을 반복하여 
         (1,0)에 도달 한다.*/
            while (1) { \
                printf("(%d,%d)\n",x,y);
                if (x == 1 && y ==0) break;
                if (x == m-1){
                    y--;
                    printf("(%d,%d)\n",x,y);
                    x--;
                }
                else if(x == 1)
                {
                    y--;
                    printf("(%d,%d)\n",x,y);
                    x++;
                }
                else if(y % 2 == 0) x--;
                else if(y % 2 == 1) x++;
            }

        }
      // CASE3 : 짝수X홀수 Toroidal Grid
        else if(m%2 == 0 && n%2 == 1)
        {
         /* (0,0)에서 시작하여 (0,n-1)까지 이동경로를 출력한다. */   
            while (1) { 
                
                printf("(%d,%d)\n",x,y);
                if(y == n-1) break;
                y++;
            }
            x = m-1; // 오른쪽 아래 
            y = n-1; // 모서리로 이동한다.
         
            /* (m-1,n-1)부터 시작하여 (1,n-1)까지 이동경로를 출력 후
         (1,n-2)부터 시작하여 (m-1,n-2)까지 이동경로를 출력하다.
         위의 과정을 반복하여 (1,0)에 도달한다. */
            while (1) {
                printf("(%d,%d)\n",x,y);
                if (x == 1 && y ==0) break;
                if(x == m-1 && y == n-1) x--;
                else if(y % 2 == 0 && x != 1) x--;
                else if(x == 1){
                    y--;
                    printf("(%d,%d)\n",x,y);
                    x++;
                }
                else if(y % 2 == 1 && x != m-1)x++;
                else{
                    y--;
                    printf("(%d,%d)\n",x,y);
                    x--;
                }
            }
        }
      // CASE4 : 짝수 X 짝수 Grid (= 홀수 X 짝수)
        else if(m%2 == 0 && n%2 == 0)
        {
         /* (0,0)에서 시작하여 (0,n-1)까지 이동경로를 출력한다.  */
            while (1) { 
                printf("(%d,%d)\n",x,y);
                y++;
                if(y == n-1) break;
            }
         /* (0,n-1)부터 (m-1,n-1)까지 이동경로를 출력한다. */
            while (1) { 
                printf("(%d,%d)\n",x,y);
                x++;
                if(x == m-1) break;
            }
            
         /* (m-1,n-2)부터 (1,n-2)까지 이동경로를 출력 후
         (1,n-3)부터 (m-1,n-3)까지 이동경로 출력을 반복하여 
         (1,0)에 도달 한다.*/
            while (1) {
                printf("(%d,%d)\n",x,y);
                if (x == 1 && y ==0) break;
                if (x == m-1){
                    y--;
                    printf("(%d,%d)\n",x,y);
                    x--;
                }
                else if(x == 1)
                {
                    y--;
                    printf("(%d,%d)\n",x,y);
                    x++;
                }
                else if(y % 2 == 0) x--;
                else if(y % 2 == 1) x++;     
            }
      }
    }
    return 0;
}
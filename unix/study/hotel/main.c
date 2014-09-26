#include <stdio.h>

#define NROOMS 5

int main(void){
         int j;
         char *getoccupier(int), *p;

         for(j=1; j<=NROOMS; j++){
                 if(p=getoccupier(j))
                         printf("Room %2d, %s\n", j, p);
                 else
                         printf("Error on room %d\n", j);
         }

         return 0;
 }


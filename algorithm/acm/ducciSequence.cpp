#include <stdio.h>
#include <string.h>

#define MAX_SIZE 15

int main(void){
	FILE *in;
	int iTestCase, size;
	int tuples[MAX_SIZE];

	in = fopen("input.txt", "r");
	fscanf(in, "%d", &iTestCase);

	while(iTestCase--){
		// ~ initial variable
		fscanf(in, "%d", &size);
		
	}

	return 0;
}
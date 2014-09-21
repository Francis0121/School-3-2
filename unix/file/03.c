#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define PERMS 0644 // O_CREAT을 사용하는 open을 위한 permission

char *filename = "newfile";

int main(void){
	int filedes;
	if((filedes = open(filename, O_RDWR|O_CREAT, PERMS)) == -1){
		printf("Couldn`t create %s\n", filename);
		exit(1);
	}
	
	return 0;
}

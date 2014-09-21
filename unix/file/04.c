#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 512

int main(void){
	char buffer[BUFSIZE];
	int filedes;
	ssize_t nread;
	int total=0;

	if((filedes=open("anotherfile", O_RDONLY))==-1){
		printf("Error in opening anotherfile\n");
		exit(1);	
	}		

	while((nread=read(filedes, buffer, BUFSIZE))>0){
		total+=nread;
	}

	printf("Total chars in anotherfile: %d\n", total);

	return 0;
}

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int glob = 6; // external variable in initialized data
int main(void){
	int var; // automatic variable on the stack
	pid_t pid;
	
	var = 88;
	
	printf("before vfork\n"); // we don't flush stdout
	
	if((pid = vfork()) < 0)
		perror("vfork error");
	else if(pid == 0){	// child
		glob++;		// modify parent' variable
		var++;
		exit(0);	// child terminates
	}
	// parent
	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	
	return 0;
}

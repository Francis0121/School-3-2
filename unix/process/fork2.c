#include <sys/types.h>
#include <stdio.h>

int glob = 6; // external variable in initialized data
char buf[] = "a write to stout\n";

int main(void){
	int var; // automatic variable on the stack
	pid_t pid;
	var = 88;
	
	if(write(2, buf, sizeof(buf)-1) != sizeof(buf)-1)
		perror("write error");
	printf("befor fork\n"); // we don't flush stdout

	if((pid =fork()) < 0)
		perror("fork error");
	else if(pid == 0){
		glob++;
		var++;
	}else
		sleep(2);

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);

	return 0;
}

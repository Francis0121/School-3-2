#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
	pid_t pid;
	
	printf("Just one process so far\n");
	printf("Calling fork ...\n");

	pid = fork();
	
	if(pid == 0)
		printf("I'm the child\n");
	else if(pid > 0)
		printf("I'm the parent, child has pid %d\n", pid);
	else
		printf("Fork returned error code, no child\n");

	return 0;
}


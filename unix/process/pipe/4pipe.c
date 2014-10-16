#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAXLINE 512

int main(int argc, char **argv){
	int n, fin, fd[2];
	pid_t pid;
	char line[MAXLINE];

	// pipe
	if( pipe(fd) < 0){
		perror("pipe error");	
		exit(-1);
	} 

	fin = open(argv[1], O_RDONLY);
	
	// fork
	if( (pid = fork() ) < 0){
		perror("fork error");
		exit(-1);
	}// parent
	else if(pid > 0){
		close(fd[0]);
		while((n = read(fin, line, MAXLINE))){
			write(fd[1], line, n);
		}
	}// child
	else{
		close(fd[1]);
		
		close(0); // clost stdin
		dup(fd[0]); // duplicate stdin (redirection)
		execl("/bin/more", "more", (char *) NULL);
	}

	return 0;
}

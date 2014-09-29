/**************************************************
*	lookout - 화일이 변경될 때 메시지 프린트
**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#define MFILE 10

void cmp(const char *, time_t);
struct stat sb;

int main(int argc, char **argv){
	int j;
	time_t last_time[MFILE+1];
	
	if(argc < 2){
		fprintf(stderr, "usage: lookout filename ...\n");
		exit(1);
	}	

	if(--argc > MFILE){
		fprintf(stderr, "lookout: too many filenames\n");
		exit(1);
	}

	for(j=1; j<=argc; j++){
		if(stat(argv[j], &sb) == -1){
			fprintf(stderr, "lookout: couldn't stat%s\n", argv[j]);
			exit(1);
		}
		last_time[j] = sb.st_mtime;
	}
		
	// infinite loop for file change
	while(1){
		for(j=1; j<=argc; j++){
			cmp(argv[j], last_time[j]);
		}
		// delay 60 == UNIX library rooutin
		sleep(60);
	}

	return (0);
}

void cmp(const char *name, time_t last){
	if(stat(name, &sb) == -1 || sb.st_mtime != last){
		fprintf(stderr, "lookout: %s changed\n", name);
		exit(0);
	}
}

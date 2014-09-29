/*****************************************
*	addx - 화일에 수행허가를 추가
*****************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#define XPERM 0100 // User Permission

int main(int argc, char **argv){
	int k;
	struct stat statbuf;

	// 인수 리스트의 모든 화일에 대한 루프
	for(k=1; k<argc; k++){
		// 현행 화일 모드 얻음
		if(stat(argv[k], &statbuf) == -1){
			fprintf(stderr, "addx: couldn't stat %s\n", argv[k]);
			continue;	
		}
		
		// 비트별 OR 연산을 사용하여 수행허가의 추가를 시도
		statbuf.st_mode |= XPERM;
		if(chmod(argv[k], statbuf.st_mode) == -1)
			fprintf(stderr, "addx: couldn't change mode for %s\n", argv[k]);
	}	

	exit(0);

	return 0;
}


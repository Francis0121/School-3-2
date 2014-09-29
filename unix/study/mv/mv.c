#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *usage = "usage: move file1 file2\n";

// main은 command line에 의해 표준적인 방법으로 전달된 인수를 사용한다.

int main(int argc, char **argv){
	
	if(argc != 3){
		fprintf(stderr, usage);
		exit(1); // stdlib.h
	}
	
	// Link를 연결해준다음에
	if(link(argv[1], argv[2]) == -1){
		perror("link failed\n");
		exit(1);
	}

	// 그 링크중 첫번째 링크에 대해 해제를 해주면
	if(unlink(argv[1]) == -1){
		perror("unlink failed\n");
		unlink(argv[2]);
		exit(1);
	}		

	// 성공
	printf("Succeeded\n");
	exit(0);
	
	return 0;
}

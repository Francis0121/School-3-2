#include <stdio.h>
#include <stdlib.h> // exit 호출을 위한 것
#include <fcntl.h>

char *workfile = "junk"; // workfile 이름을 정의

int main(void){
	int filedes;

	// ~ <fcntl.h>에 정의된 O_RDWR을 사용하여 open
	// ~ 파일을 읽기/쓰기로 open한다.
	if((filedes = open(workfile, O_RDWR)) == -1){
		printf("Couldn`t open %s\n", workfile);
		exit(1);	// error so exit	
	}

	// 이 프로그램 나머지부부분
	exit(0); // normal exit

	return 0;
}

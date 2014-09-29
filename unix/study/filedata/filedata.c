/***********************************************
*	filedata - 한 화일에 관한 정보를 출력
************************************************/

#include <stdio.h>
#include <sys/stat.h>

// 허가 비트가 설정되어 있는지 결정하기 위해 octarray 사용
static short octarray[9] = { 	0400, 0200, 0100, 
				0040, 0020, 0010, 
				0004, 0002, 0001 };

// 화일 허가에 대한 기호화 코드 끝부분의 null 때문에 길이가 10문자이다.
static char perms[10] = "rwxrwxrwx";

int filedata(const char *pathname){
	struct stat statbuf;
	char descrip[10];
	int j;
	
	if(stat(pathname, &statbuf) == -1){
		fprintf(stderr, "Couldn't stat %s\n", pathname);
		return (-1);	
	}

	// 허가를 읽기 가능한 형태로 바꾼다.
	for(j=0; j<9; j++){
		// 비트별 AND를 사용하여 허가가 설정되었는지 테스트
		if(statbuf.st_mode & octarray[j])
			descrip[j] = perms[j];
		else
			descrip[j] = '-';
	}
	descrip[9] = '\0'; // 하나의 문자열을 가지도록 확인
	
	// 화일정보 출력
	printf("\nFile %s :\n", pathname);
	printf("Size %ld bytes\n", statbuf.st_size);
	printf("User-id %d, Group-id %d\n\n", statbuf.st_uid, statbuf.st_gid);
	printf("Permission :%s\n", descrip);
	return (0);
}



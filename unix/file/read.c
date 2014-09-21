#include <fcntl.h>
#include <unistd.h>

int main(void){
	int fd;
	ssize_t nread;	// <sys/types.h>에 정의된 type, 일부 기본 type은 <unistd.h>에서도 정의
	char buf[1024];
	
	// fd -> File descriptor 값을 return : 시스템에 의해 결정되는 음이 아닌 정수값
	fd = open("data", O_RDONLY); // <fcntl.h>에 정의

	nread = read(fd, buf, 1024); // 문자 또는 바이트의 linear sequence 만을 다룬다.

	close(fd);

	return 0;
}

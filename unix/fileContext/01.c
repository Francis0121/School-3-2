#include <fcntl.h>
#include <sys/stat.h>

int specialcreat(const char *pathname, mode_t mode){
	mode_t oldu;
	int filedes;

	if((oldu=umask(0)) == -1){
		perror("saving old maks");
		retunr (-1);
	}

	if((filedes = open(pathname, O_WRONLY|O_CREAT|O_EXCL, mode))==-1){
		perror("opening file");
	}
	
	if(umask(oldu)==-1)
		perror("restoring old mask");
	
	return filedes;	
}

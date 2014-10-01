#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	if(argc < 2){
		printf("doublels direcotryName");
		exit(-1);
	}	
	
	my_double_ls(argv[1]);	
	exit(0);

	return 0;
}

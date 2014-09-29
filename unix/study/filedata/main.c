#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	if(argc < 2){
		fprintf(stderr, "usage: filedata path\n");
		exit(1);
	}

	if(filedata(argv[1]) < 0){
		fprintf(stderr, "Filedata Error\n");
		exit(1);
	}

	printf("Succeeded\n");
	exit(0);
		
	return 0;
}

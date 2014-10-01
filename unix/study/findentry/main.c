#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	char *entry;
	
	if(argc < 3){
		printf("findentry directoryname suffix\n");
		exit(-1);
	}

	entry = find_entry(argv[1], argv[2], 1);
	
	printf("%s\n", entry);

	return 0;
}

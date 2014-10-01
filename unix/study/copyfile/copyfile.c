/*************************
* Cope from "name1" to "name2"
*************************/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 512 // read dump size
#define PERM 0644 // new file permssion

// ~  Cope from "name1" to "name2"
int copyfile(const char *name1, const char *name2){
	int infile, outfile;
	ssize_t nread; // include <unistd.h> ssize_t (part of special type)
	char buffer[BUFSIZE];
	
	// O_RDONLY (option ready only)
	if((infile=open(name1, O_RDONLY))<0)
		return (-1); // file read error return -1

	// O_WRONLY (option write only)
	// O_CREATE (not exist file -> file create)
	// O_TRUNC (file remove 0 byte)
	if((outfile=open(name2, O_WRONLY|O_CREAT|O_TRUNC, PERM))<0){ // PERM -> O_CREATE option 
								// 644 -rw-r--r-- (user, group, other)
		close(infile);
		return (-2); // file create, write error return -2
	}

	// Read from name1 BUFSIZE character
	while((nread=read(infile, buffer, BUFSIZE))>0){
		if(write(outfile, buffer, nread) < nread){
			close(infile);
			close(outfile);
			return(-3); // Write Error
		}	
	}
	
	close(infile);
	close(outfile);

	if(nread<0)
		return (-4); // Last read error
	else
		return (0);
}

int main(int argc, char* argv[]){
	
	char *copyFileName, *newFileName; 

	if(argc < 3){
		printf("Need to file Name\n");
		printf("\tFormat : copyfile filename1 filename2\n");
		return 0;
	}

	copyFileName = argv[1];
	newFileName = argv[2];

	// ~ Return 0 Success. Return negative integer error. ( -1, -2, -3, -4 )
	switch (copyfile(copyFileName, newFileName)){
		case 0:
			printf("Success\n");
			break;
		case -1:
			printf("%s open error\n", copyFileName);
			break;
		case -2:
			printf("%s open error\n", newFileName);
			break;
		case -3:
			printf("Write error\n");
			break;
		case -4:
			printf("Last read error\n");
			break;
	}
	
	return 0;
}
















/*************************
* Cope from "name1" to "name2"
*************************/
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 512 // read dump
#define PERM 0644 // new file permssion

// ~  Cope from "name1" to "name2"
int copyfile(const char *name1, const char *name2){
	int infile, outfile;
	ssize_t nread;
	char buffer[BUFSIZE];

	if((infile=open(name1, O_RDONLY))<0)
		return (-1);

	if((outfile=open(name2, O_WRONLY|O_CREAT|O_TRUNC, PERM))<0){
		close(infile);
		return (-2);
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

int main(void){
	// ~ Return 0 Success. Return negative integer error. ( -1, -2, -3, -4 )
	return copyfile("test.in", "test.out");	
}

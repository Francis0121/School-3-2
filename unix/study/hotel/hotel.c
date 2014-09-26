/************************************************************
*	getoccupier - Get customer name from residents file
************************************************************/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 41

char namebuf[NAMELENGTH];
int infile = -1;

char *getoccupier(int roomno){
	off_t offset; // <unistd.h> declare special type off_t
	ssize_t nread; // <unistd.h> declare special type ssize_t

	if(infile == -1 && (infile = open("residents", O_RDONLY)) == -1)
		return (NULL);
	
	offset = (roomno - 1) * NAMELENGTH;
	
	if(lseek(infile, offset, SEEK_SET) == -1)
		return (NULL);

	if((nread = read(infile, namebuf, NAMELENGTH)) <= 0)
		return (NULL);
	
	namebuf[nread-1] = '\0';
	return (namebuf);
}


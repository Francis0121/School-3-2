#include <stdio.h>
#include <dirent.h>

int my_double_ls(const char *name){
	struct dirent *d;
	DIR *dp;

	// Directory open, Judgement Fail
	if((dp = opendir(name)) == NULL)
		return (-1);
	
	// Searching Directory and infinite loop. Exist inode directory print
	while(d = readdir(dp)){
		if(d->d_ino != 0){
			printf("%s\n", d->d_name);
		}
	}

	// Back directory start
	rewinddir(dp);
	// Re Printf directroy
	while(d = readdir(dp)){
		if(d->d_ino != 0){
			printf("%s\n", d->d_name);
		}
	}

	closedir(dp);
	return(0);
}

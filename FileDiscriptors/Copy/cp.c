#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char**argv){
	// checking if input arguments are valid
	if(argc != 3){
		printf("cp src dst\n");
		return 1;
	}
	char *inputName = argv[1];
	char *outputName = argv[2];

	// opening files to read and write
	// O means open
	int srcFd = open(inputName, O_RDONLY, 0);
	// S=>set= I->Inode, R=>Read, W=>Write. This permission is equivalent to 0644
	int dstFd = open(outputName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	// checking if files are opened successfully
	if(srcFd == -1){
		printf("Error while opening file %s\n", inputName);
		return 2;
	}

	if(dstFd == -1){
		printf("Error while opening file %s\n", outputName);
		close(srcFd);
		return 3;
	}
	
	// creating a buffer and reading chunks from srcFd and writing it to dstFd
	char buff[BUFSIZE];
	int n_read = 0, n_written = 0;
	while((n_read = read(srcFd, buff, BUFSIZE)) > 0){
		n_written = write(dstFd, buff, n_read);
		if(n_written != n_read){
			printf("Error while writing in %s file\n", outputName);
			close(srcFd);
			close(dstFd);
			return 4;
		}
	}
	// if n_read is 0 it means end of file
	// but if n_read was minus value it means error
	if(n_read < 0){
		printf("Error while reading from the %s file\n", inputName);
		close(srcFd);
		close(dstFd);
		return 5;
	}

	return 0;
}

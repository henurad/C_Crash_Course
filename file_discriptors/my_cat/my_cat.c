#include <stdlib.h> // for exit()
#include <unistd.h> // for read() and write()
#include <fcntl.h> // for open()
#include <stdio.h>

#define BUFSIZE 1024

int main(int argc, char **argv){
	if(argc != 2){
		fprintf(stderr, "mycat filename\n");
		exit(1);
	}
	
	int fd = open(argv[1], O_RDONLY, 0);
	if(fd == -1){
		fprintf(stderr, "No File\n");
		exit(2);
	}
	int n = 0;
	char buff[BUFSIZE];
	while((n = read(fd, buff, BUFSIZE)) > 0){
		if(n != write(1, buff, n)){
			fprintf(stderr, "error while showing the text\n");
			close(fd);
			exit(1);
		}
	} 

	close(fd);
	if (n == -1){
		fprintf(stderr, "Error while reading the file\n");
		return 1;
	}

	return 0;
}

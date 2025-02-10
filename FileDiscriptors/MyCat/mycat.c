#include <stdlib.h> // for exit()
#include <unistd.h> // for read() and write()
#include <fcntl.h> // for open()

#define BUFSIZE 1024

int main(int argc, char **argv){
	if(argc != 2){
		write(2, "mycat filename\n",16);
		exit(1);
	}
	
	int fd = open(argv[1], O_RDONLY, 0);
	if(fd == -1){
		write(2, "No File\n", 9);
		exit(2);
	}
	int n = 0;
	char buff[BUFSIZE];
	while((n = read(fd, buff, BUFSIZE)) != 0){
		write(1, buff, n);
	} 
	close(fd);

	return 0;
}

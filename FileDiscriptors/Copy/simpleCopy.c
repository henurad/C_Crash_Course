/**
 * This is a simple program that just copies every std input to std output
*/

#include <unistd.h>

#define BUFSIZE 1024

int main(){
	char buf[BUFSIZE];
	int n = 0;
	
	while((n = read(0, buf, BUFSIZE)) > 0){
		write(1, buf, n);
	}

return 0;
}

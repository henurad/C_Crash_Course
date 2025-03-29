#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 1024

int getchar(){
	static char buff[BUFSIZE];
	static char *bufp = buff;
	static int n = 0;
	
	if(n == 0){ /* buffer is empty */
		n = read(0, buff, BUFSIZE);
		bufp = buff;
	}
	
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int main(){
	char c;
	do{
		c = getchar();
		printf("Entered character is: %c\n", c);
	} while(c != 'e');
	return 0;
}

#include "mystdio.h"

int main(){
	char c;// = getc(stdin);
	while((c = getchar()) != 'e'){
		putchar(c);
	}
	return 0;
}

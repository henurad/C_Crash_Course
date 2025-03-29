#include <unistd.h>
#include <stdio.h>

int getchar(){
	char c;
	// c must be a char, because read needs a char pointer. 
	// Casting c to unsigned char eliminates any problem of sign extension in return;
	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int main(){
	char ch;
	do{
		ch = getchar();
		printf("Entered char is %c\n", ch);
	} while(ch != 'e');
	return 0;
}

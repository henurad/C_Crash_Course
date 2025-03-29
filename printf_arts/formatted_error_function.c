#include <stdio.h> // for vfprintf()
#include <stdlib.h> // for exit()
#include <stdarg.h> // for va_list, va_start, va_end

void error(char *fmt, ...){
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	exit(1);
}

int main(){
	int age = -1;
	if(age < 0){
		error("%d is invalid age. Age cannot be a negative number!\n", age);
	}
	return 0;
}

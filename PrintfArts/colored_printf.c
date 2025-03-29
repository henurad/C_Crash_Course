#include <stdio.h>

#define textColorRed "\033[31m"
#define bgColorBlack "\033[40m"
#define bgColorWhite "\033[47m"
#define resetCode "\033[0m"


int main(){
	printf("%s%sThis text is red with black background%s\n", textColorRed, bgColorBlack, resetCode);
	printf("This text is normal\n");
	printf("%s%sThis text is red with white background%s\n", textColorRed, bgColorWhite, resetCode);
	return 0;
}

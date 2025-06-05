#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
	printf("%s\n", argv[0]);
	char ch;
	if (strcmp(argv[0], "lower") == 0 || strcmp(argv[0], "./lower") == 0){
		while((ch = getchar()) != EOF){
			putchar(tolower(ch));
		}
	} else if (strcmp(argv[0], "upper") == 0 || strcmp(argv[0], "./upper") == 0) {
		while((ch = getchar()) != EOF){
			putchar(toupper(ch));
		}
	}

	return 0;
}

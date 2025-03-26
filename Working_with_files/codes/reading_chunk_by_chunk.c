#include <stdio.h>
#include <string.h>

int main(){
	FILE *fptr = fopen("./names.txt", "r");
	if(fptr != NULL){
		const unsigned int N = 5;
		char buff[N];
		while(fgets(buff, N, fptr) != NULL){
			printf("%s\n", buff);
			printf("%d\n\n", strlen(buff));
		}
		fclose(fptr);
	} else {
		printf("The file names.txt doesn't exist \n");
	}
	return 0;
}

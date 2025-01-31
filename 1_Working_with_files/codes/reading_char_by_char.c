#include <stdio.h>

int  main(){
	FILE *fptr = fopen("./names.txt", "r");
	if(fptr != NULL){
		char c;
		while((c = fgetc(fptr)) != EOF){
			printf("%c", c);	
		}
		fclose(fptr);
	} else {
		printf("The file names.txt doesn't exits");
	}
	return 0;
}

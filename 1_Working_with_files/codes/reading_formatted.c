#include <stdio.h>

int main(){
	FILE *fptr = fopen("./names.txt", "r");
	if(fptr != NULL){
		char name[50];
		int age;
		while(fscanf(fptr, "%s %d", &name, &age) == 2){
			printf("name is: %s\n", name);
			printf("age is: %d\n\n", age);
		}
		fclose(fptr);
	} else {
		printf("Can't open the file names.txt\n");
	}
	return 0;
}

#include <stdio.h>

struct Person{
	char name[50];
	int age;
};

int main(){
	struct Person p1 = {"Henurad", 20};
	struct Person p2 = {"John", 24};

	struct Person readPersons[2];

	FILE *fptr = fopen("./names.bin", "wb");
	if(fptr != NULL){
		fwrite(&p1, sizeof(p1), 1, fptr);
		fwrite(&p2, sizeof(p2), 1, fptr);
		fclose(fptr);
	} else {
		printf("Can't open names.txt file to write.\n");
	}

	fptr = fopen("./names.bin", "rb");
	if(fptr != NULL){
		if(fread(readPersons, sizeof(struct Person), 2, fptr)){
			for(size_t i = 0; i < 2; i++){
				printf("person %d: %s %d\n", i, readPersons[i].name, readPersons[i].age);
			}
	
		} else {
			printf("Can't read persons from names.bin\n");
		}	
		fclose(fptr);
	} else {
		printf("Can't open names.txt file to read.\n");
	}

	return 0;
}

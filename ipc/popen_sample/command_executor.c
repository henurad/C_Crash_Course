#include <stdio.h>
#include <stdlib.h>

void execute(char *command, void (*resultFcn)(char *));
void resultFunction(char *);

int main(){
	execute("./counter", resultFunction);
	return 0;
}

void execute(char *command, void (*resultFcn)(char *)) {
	FILE *fp = popen(command, "r");

	char buffer[1024];
	while(fgets(buffer, sizeof(buffer), fp) != NULL) {
		resultFcn(buffer);
	}
}

void resultFunction(char *result) {
	printf("%s", result);
}

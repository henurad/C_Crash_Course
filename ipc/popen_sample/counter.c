#include <unistd.h>
#include <stdio.h>

int main(){
	for(int i = 0; i < 25; i++){
		printf("iteration number :%d\n", i);
		fflush(stdout);

		sleep(1);
	}
	return 0;
}	

#include <stdio.h> // for printf() function
#include <unistd.h> // for usleep() function

void clearScreen(){
	printf("\033[H\033[2J");
}

int main(){
	for(int i = 0; i < 100; i++){
		usleep(100000);
		clearScreen();
		printf("i: %d\n", i);
		fflush(stdout);
	}
}

#include <stdio.h> // for printf() and fflush()
#include <unistd.h> // for usleep() 

void printProgressBar(int percentage, int barWidth){
	int pos = percentage * barWidth / 100;

	printf("[");
	for(int i = 0; i < pos; i++)
		printf("=");

	for(int i = pos; i < barWidth; i++)
		printf(" ");

	printf("] %d%%", percentage);
	printf((pos == barWidth)? "\n": "\r");
	fflush(stdout);
}

int main(){
	for(int i = 0; i <= 100; i++){
		printProgressBar(i, 70);
		usleep(50000);
	}
	return 0;
}

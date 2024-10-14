#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	printf("Enter an integer: ");
	scanf("%i",&n);
	
	if (n>=0)
		printf("%i",n);

	else if (n<0)
		printf("%i",-n);
		
	return 0;
}
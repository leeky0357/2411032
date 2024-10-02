#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a;
	
	
	printf("Input the year: ");
	scanf("%i",&a);
	
	printf("Is the year %i the leap year?",a);
	printf("%i", a%4==0 && a%100!=0 || a%400==0);
		
	return 0;
}
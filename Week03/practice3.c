#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	char c;
	
	printf("enter a character: ");
	scanf("%c", &c);
	
	char next_c = c+1;
	
	printf("the next character of %c (%d) is %c (%d))",c,c,c+1,c+1);
	return 0;
}
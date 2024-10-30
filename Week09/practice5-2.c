#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

static int sum=1;
int main(void)
{
	int sum=0;
	
	printf("sum = %d\n", sum);
	
	return 0;
 } 
 
 extern int sum;
 
 int sum1(void)
 {
 	sum = sum + 1;
 }
 



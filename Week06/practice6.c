#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int n;
	int t=0;
	int answer = 50;
	
	do
	{
	printf("Guess a number:");
	t++;
	scanf("%i",&n);
	
	if(n<answer)
		printf("Low!\n");
	
	else if(n>answer)
		printf("High!\n");
	
	else if(n==answer)
		{printf("Congratulation! Trials: %i",t);
		break;}
		
	}while(1);
	
	return 0;
}
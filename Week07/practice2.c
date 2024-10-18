#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b;
	
	printf("Enter the integers: ");
	scanf("%i %i",&a,&b);
	
	printf("Result - Sum : %i, Square : %i, Max : %i", sumTwo(a, b), square(a), get_max(a,b));
	
	return 0;
	
}
	int sumTwo(int a, int b){
		return (a+b);
	}
	
	int square(int n){
		return(n*n);
	}
	
	int get_max(int x, int y){
		if(x > y) return (x);
		else return (y);
	}



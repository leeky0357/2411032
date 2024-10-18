#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int get_integer();
int factorial(int n);
int combination(int n, int r);
int n, r;

int main(void) {

	int n = get_integer();
	int r = get_integer();
	
	 if (r > n || n < 0 || r < 0) {
        printf("Invalid input.");}
        else{
		printf("The result of C(%i, %i) is %i", n, r, combination(n, r));
		}
	return 0;
    	
}

	int get_integer (){
		int a;
		printf("Enter the value: ");
		scanf("%i",&a);
;
		return a;
	}
	
	int factorial(int n) {
	    int res = 1;
	    for (int i = 1; i <= n; i++)
	        res *= i;
	    return res;
	}
	
	int combination(int n, int r) {
	    return factorial(n) / (factorial(r) * factorial(n - r));
	}
	


#include <stdio.h>
#include <stdlib.h>
#define ROWS	3
#define COLS	3
void addMatrix(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]);
void printMatrix(int C[ROWS][COLS]);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	int A[ROWS][COLS] = {
		{2,3,0},
		{8,9,1},
		{7,0,5}};
	int B[ROWS][COLS] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}};
	int C[ROWS][COLS];
	
	addMatrix(A,B,C);
	printMatrix(C);
	
	return 0;
}

void addMatrix(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
	int i, j;
	
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			C[i][j] = A[i][j] + B[i][j];
}
void printMatrix(int C[ROWS][COLS])
{
	int i, j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ", C[i][j]);		
		printf("\n");
	}
}
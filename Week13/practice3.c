#include <stdio.h>
#include <stdlib.h>
#define STUDENTNUM 4
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student{
	int ID;
	int score;
};

void main(void){
	struct student s[STUDENTNUM];
	int sum = 0;
	struct student max_s = {0, 0};
	
	for (int i = 0; i< STUDENTNUM; i++){
		printf("Input the ID : ");
		scanf("%d", &s[i].ID);
		printf("Input the score : ");
		scanf("%d", &s[i].score);
		
		if (s[i].score > max_s.score){
			max_s = s[i];
		}
		
		sum += s[i].score;	
	}
	
	double average = sum / (double) STUDENTNUM;
	printf("The average of the score : %f\n", average);
	
	printf("The highest score - ID : %d, score : %d\n", max_s.ID, max_s.score);
	
}
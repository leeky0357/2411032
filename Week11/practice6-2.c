#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main(void){
	FILE*fp = NULL;
	char word[100];
	
	fp = fopen("sample.txt", "r");
	if(fp == NULL)
		printf("cannot open the file\n");
		
	while(fgets(word, sizeof(word), fp) != NULL){
		printf("%s", word);
	}
	fclose(fp);
}
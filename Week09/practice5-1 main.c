#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int all_files;			//전역 변수 선언

extern void sub();			//sub 함수가 다른 곳에 정의되어 있음

int main(void)
{
	sub();				//sub 함수 호출-> all_files 값 변경
	printf("%d\n", all_files);			//변경된 all_files 값 출력
	return 0;
}


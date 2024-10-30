#include <stdio.h>
#include <stdlib.h>


extern int all_files;			//all_files 변수가 다른 곳에 이미 선언
void sub(void)
{
	all_files = 10;			//전체 접근 가능
}
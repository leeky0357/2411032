#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void sub(void);

int main(void) 
{
	int i;
	for(i=0;i<3;i++)
		sub();
	return 0;
}

void sub(void)
{
	int auto_count = 0;
	static int static_count = 0;
	auto_count++;
	static_count++;		//static 키워드 역할- 변수가 함수 내부에 선언되더라도 초기화는 한 번만, 함수가 다시 호출될 떄 이전 값 유지
	printf("auto_count=%d\n", auto_count);
	printf("static_count=%d\n", static_count);
}
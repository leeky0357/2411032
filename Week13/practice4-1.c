#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct point{
	int x;
	int y;
};

int getArea(struct point p1, struct point p2){

    int w = abs(p2.x - p1.x);   //width
    int h = abs(p2.y - p1.y);  //height
   
    return w * h;          
}

int main(int argc, char *argv[]){
	
	struct point p1, p2;
	int area;
	
	
    printf("Input the coordinate p1 (x y) : ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Input the coordinate p2 (x y) : ");
    scanf("%d %d", &p2.x, &p2.y);

	area = getArea(p1, p2);
    printf("Area : %d\n", area);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main(void) {
    char str[30] = "happy C programming";

    printf("The length of string \"%s\" : %i", str, strlen(str));
}
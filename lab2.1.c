#include <stdio.h>

int main(void){
    int ascii;
    printf("Enter an integer from 0 - 255\n");
    scanf("%d", &ascii);
    printf("The ascii character is: %c\n", ascii);
    return 0;
}
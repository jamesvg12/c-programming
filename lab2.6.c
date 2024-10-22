#include <stdio.h>
#define CONVERSION 0.92
#define INPUTS 10

int main(void){
    double dollars[INPUTS];
    double euros[INPUTS];
    for(int i = 0; i < INPUTS; i++){
        printf("Enter the dollar amount\n");
        scanf("%lf", &dollars[i]);
        euros[i] = dollars[i] * CONVERSION;
        printf("%.2lf dollars is equivalent to %.2lf euros\n", dollars[i], euros[i]);
    }
}
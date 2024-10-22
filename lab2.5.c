#include <stdio.h>
#define INPUTS 10
#define WEEK 7

int main(void){
    int days[INPUTS];
    int weeks[INPUTS];
    int remainder[INPUTS];
    for(int i = 0; i < INPUTS; i++){
        printf("Enter the amount of days\n");
        scanf("%d", &days[i]);
        weeks[i] = days[i] / WEEK;
        remainder[i] = days[i] % WEEK;
        printf("%d days is equivalent to %d weeks and %d days\n", days[i], weeks[i], remainder[i]);
    }
}
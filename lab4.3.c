#include <stdio.h>

int gcd(int x, int y){
    if (y == 0){
        return x;
    }
    else{
        return gcd(y, x % y);
    }
}

int gcd2(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main(){
    int x = 0;
    int y = 0;
    printf("Enter the first number to be inputted in the GCD function\n");
    scanf("%d", &x);
    printf("Enter the first number to be inputted in the GCD function\n");
    scanf("%d", &y);
    printf("The answer is %d", gcd(x , y));
}
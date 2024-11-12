#include <stdio.h>

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(){
    int num;
    printf("Enter the number to be passed through the factorial function\n");
    scanf("%d", &num);
    int result = factorial(num);
    printf("%d! = %d", num, result);
}
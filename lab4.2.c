#include <stdio.h>

int fibonacci(int n){
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int fibonacci2(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int a = 0, b = 1, fib;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;        
        b = fib;      
    }
    return fib;
}


int main(){
    int n = 0;
    printf("Enter number to be inputted in the fibonacci function\n");
    scanf("%d", &n);
    printf("The answer is %d", fibonacci(n));
}
#include "lab4.7.2.c"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Factorial (Iterative)
long fact(int n) {
    long ans;
    for (ans = 1; n > 1; n--)
        ans *= n;
    return ans;
}

// Factorial (Recursive)
long rfact(int n) {
    long ans;
    if (n > 0)
        ans = n * rfact(n - 1);
    else
        ans = 1;
    return ans;
}

// Fibonacci (Recursive)
int fibonacci(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Fibonacci (Iterative)
int fibonacci2(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, fib;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

// GCD (Recursive)
int gcd(int x, int y){
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

// GCD (Iterative)
int gcd2(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// String reversal (Recursive)
void reverseString(char str[], int left, int right) {
    if (left >= right) {
        return;
    }
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    reverseString(str, left + 1, right - 1);
}

// Finding the most common character
char mostCommonCharacter(char str[]) {
    int count[256] = {0};
    int max_count = 0;
    char most_common = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        count[(int)str[i]]++;
        if (count[(int)str[i]] > max_count) {
            max_count = count[(int)str[i]];
            most_common = str[i];
        }
    }
    return most_common;
}

// Check if the string contains numbers
int noNumbers(char str[], int len) {
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Apply Ceil (without math.h)
void applyCeil(double *x) {
    if (*x > (int)(*x)) {
        *x = (int)(*x) + 1;
    } else if (*x < 0 && *x != (int)(*x)) {
        *x = (int)(*x);
    } else {
        *x = (int)(*x);
    }
}

// Apply Floor (without math.h)
void applyFloor(double *x) {
    if (*x < 0 && *x != (int)(*x)) {
        *x = (int)(*x) - 1;
    } else {
        *x = (int)(*x);
    }
}

// Convert decimal number to hexadecimal
void decimalToHex(int number) {
    if (number == 0) {
        return;
    }
    int remainder = number % 16;
    decimalToHex(number / 16);
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", 'A' + (remainder - 10));
    }
}

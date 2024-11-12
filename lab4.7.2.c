#ifndef LAB4_7_2_H  // Include guard
#define LAB4_7_2_H

// Factorial functions
long fact(int n);
long rfact(int n);

// Fibonacci functions
int fibonacci(int n);
int fibonacci2(int n);

// GCD functions
int gcd(int x, int y);
int gcd2(int x, int y);

// String functions
void reverseString(char str[], int left, int right);
char mostCommonCharacter(char str[]);

// Math functions
void applyCeil(double *x);
void applyFloor(double *x);
void decimalToHex(int number);

// String validation function
int noNumbers(char str[], int len);

#endif  // End of the include guard

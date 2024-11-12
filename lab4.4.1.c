#include <stdio.h>

void decimalToHex(int number) {
    // Base case
    if (number == 0) {
        return;
    }
    
    // Recursive case
    int remainder = number % 16;
    decimalToHex(number / 16);
    
    // Convert remainder to hex digit
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", 'A' + (remainder - 10)); // Map 10-15 to 'A'-'F'
    }
}

int main() {
    int number;
    printf("Enter a decimal number: ");
    scanf("%d", &number);

    if (number == 0) {
        printf("The hex value is: 0\n"); // Special case for zero
    } else {
        printf("The hex value is: ");
        decimalToHex(number);
        printf("\n");
    }

    return 0;
}

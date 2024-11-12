#include <stdio.h>
#include "lab4.7.2.c"
#include <string.h>

int main() {
    int choice;
    int n, x, y;
    double num;
    char str[100];

    while(1) {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Fibonacci (recursive)\n");
        printf("2. Fibonacci (iterative)\n");
        printf("3. GCD (recursive)\n");
        printf("4. GCD (iterative)\n");
        printf("5. Reverse String\n");
        printf("6. Most Common Character\n");
        printf("7. Apply Ceil\n");
        printf("8. Apply Floor\n");
        printf("9. Decimal to Hexadecimal\n");
        printf("10. Exit\n");
        printf("Enter your choice (1-10): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Fibonacci recursive function
                printf("Enter number for Fibonacci (recursive): ");
                scanf("%d", &n);
                printf("Fibonacci (recursive) result: %d\n", fibonacci(n));
                break;

            case 2:
                // Fibonacci iterative function
                printf("Enter number for Fibonacci (iterative): ");
                scanf("%d", &n);
                printf("Fibonacci (iterative) result: %d\n", fibonacci2(n));
                break;

            case 3:
                // GCD recursive function
                printf("Enter two numbers for GCD (recursive): ");
                scanf("%d %d", &x, &y);
                printf("GCD (recursive) result: %d\n", gcd(x, y));
                break;

            case 4:
                // GCD iterative function
                printf("Enter two numbers for GCD (iterative): ");
                scanf("%d %d", &x, &y);
                printf("GCD (iterative) result: %d\n", gcd2(x, y));
                break;

            case 5:
                // Reverse string function
                printf("Enter a string to reverse: ");
                scanf(" %[^\n]", str);  // Read an entire line with spaces
                int length = strlen(str);
                reverseString(str, 0, length - 1);
                printf("Reversed string: %s\n", str);
                break;

            case 6:
                // Most common character function
                printf("Enter a string to find the most common character: ");
                scanf(" %[^\n]", str);
                printf("Most common character: %c\n", mostCommonCharacter(str));
                break;

            case 7:
                // Apply ceil function
                printf("Enter a real number for ceil operation: ");
                scanf("%lf", &num);
                applyCeil(&num);
                printf("Ceiling value: %.2f\n", num);
                break;

            case 8:
                // Apply floor function
                printf("Enter a real number for floor operation: ");
                scanf("%lf", &num);
                applyFloor(&num);
                printf("Floor value: %.2f\n", num);
                break;

            case 9:
                // Decimal to Hex function
                printf("Enter a decimal number to convert to hexadecimal: ");
                scanf("%d", &num);
                printf("Hexadecimal value: ");
                decimalToHex((int)num);
                printf("\n");
                break;

            case 10:
                // Exit the program
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice. Please choose between 1 and 10.\n");
        }
    }
    return 0;
}

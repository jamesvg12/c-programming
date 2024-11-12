#include <stdio.h>

void applyCeil(double *x) {
    // Check if there's a decimal part
    if (*x > (int)(*x)) {  // For positive numbers with decimal parts
        *x = (int)(*x) + 1;  // Round up
    } else if (*x < 0 && *x != (int)(*x)) {  // For negative numbers with decimal parts
        *x = (int)(*x);  // Rounds up (towards zero)
    } else {
        *x = (int)(*x);  // Already an integer, no change needed
    }
}

void applyFloor(double *x) {
    if (*x < 0 && *x != (int)(*x)) { // For negative numbers with decimal part
        *x = (int)(*x) - 1;  // Round down (towards negative infinity)
    } else {
        *x = (int)(*x);  // For positive numbers or whole numbers, just truncate
    }
}

int main() {
    double num;
    double originalNum;

    printf("Enter a real number: ");
    scanf("%lf", &num);

    // Store the original number for future reference
    originalNum = num;

    // Apply ceiling and display result
    applyCeil(&num);
    printf("Ceiling value: %.2f\n", num);

    // Reset num to the original value for floor operation
    num = originalNum;

    // Apply floor and display result
    applyFloor(&num);
    printf("Floor value: %.2f\n", num);

    return 0;
}

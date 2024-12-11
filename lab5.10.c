#include <stdio.h>
#include <stdlib.h> // For atoi

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    char *endptr1, *endptr2;
    long num1 = strtol(argv[1], &endptr1, 10);
    long num2 = strtol(argv[2], &endptr2, 10);

    if (*endptr1 != '\0' || *endptr2 != '\0') {
        printf("Error: Both arguments must be numeric.\n");
        return 1;
    }

    long sum = num1 + num2;
    printf("The sum of %ld and %ld is %ld.\n", num1, num2, sum);

    return 0;
}

#include <stdio.h>

#define MAX_ATTEMPTS 5
#define CORRECT_PIN 1234

int main() {
    int pin, attempt = 0;
    int accessGranted = 0;

    while (attempt < MAX_ATTEMPTS && !accessGranted) {
        printf("Enter your PIN: ");
        scanf("%d", &pin);

        if (pin == CORRECT_PIN) {
            printf("Access granted\n");
            accessGranted = 1; 
        } else {
            attempt++;
            printf("Incorrect PIN. You have %d attempts remaining.\n", MAX_ATTEMPTS - attempt);
        }
    }

    if (!accessGranted) {
        printf("Too many incorrect attempts. You are now locked out.\n");
    }

    return 0;
}

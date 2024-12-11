#include <stdio.h>
#define LENGTH 10

void copyarray(int *source, int *destination) {
    for (int i = 0; i < LENGTH; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int ar[LENGTH] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int copy[LENGTH];

    copyarray(ar, copy);

    // Print the copied array
    printf("Copied array: ");
    for (int i = 0; i < LENGTH; i++) {
        printf("%d ", copy[i]);
    }
    printf("\n");

    return 0;
}
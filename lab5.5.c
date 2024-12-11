#include <stdio.h>
#include <stdlib.h>

#define SIZE 101 // Use 101 for larger array size

// Function to calculate f(x, y, z)
float f(int x, int y, int z) {
    return x + 6 * y + 7.2 * z;
}

int main() {
    // Dynamically allocate 3D array using pointers and malloc
    float ***arr = (float ***)malloc(SIZE * sizeof(float **));

    // Check if malloc succeeded
    if (arr == NULL) {
        printf("Memory allocation failed for the array\n");
        return 1; // Exit if memory allocation fails
    }

    // Allocate each 2D array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (float **)malloc(SIZE * sizeof(float *));
        if (arr[i] == NULL) {
            printf("Memory allocation failed for arr[%d]\n", i);
            return 1; // Exit if memory allocation fails
        }

        // Allocate the 1D arrays for each 2D row
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = (float *)malloc(SIZE * sizeof(float));
            if (arr[i][j] == NULL) {
                printf("Memory allocation failed for arr[%d][%d]\n", i, j);
                return 1; // Exit if memory allocation fails
            }
        }
    }

    // Fill the array using pointers
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            for (int z = 0; z < SIZE; z++) {
                arr[x][y][z] = f(x, y, z); // Assign result of f(x, y, z)
            }
        }
    }

    // Optional: Print some values to verify (e.g., at x = 0, y = 0, z = 0)
    printf("f(0, 0, 0) = %.2f\n", arr[0][0][0]);
    printf("f(1, 1, 1) = %.2f\n", arr[1][1][1]);
    printf("f(100, 100, 100) = %.2f\n", arr[100][100][100]);

    // Free the dynamically allocated memory
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            free(arr[i][j]); // Free each 1D array
        }
        free(arr[i]); // Free each 2D array
    }
    free(arr); // Free the 3D array

    return 0;
}
 
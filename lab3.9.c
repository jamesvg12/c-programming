#include <stdio.h>
#include <stdlib.h>

#define MIN_RANGE -100.0   // Minimum acceptable range for real numbers
#define MAX_RANGE 100.0    // Maximum acceptable range for real numbers

void process_numbers(FILE *input_file, FILE *output_file) {
    double number;
    int result;

    while ((result = fscanf(input_file, "%lf", &number)) != EOF) {
        if (result == 1) {  // Successfully read a number
            if (number >= MIN_RANGE && number <= MAX_RANGE) {
                fprintf(output_file, "%f\n", number);  // Write to output if in range
            } else {
                printf("Warning: %f is out of the acceptable range [%f, %f].\n", 
                       number, MIN_RANGE, MAX_RANGE);
            }
        } else {
            // If fscanf could not read a valid double, clear the error and skip to the next
            printf("Error: Non-numeric or invalid input encountered, skipping.\n");
            fscanf(input_file, "%*s");  // Skip the invalid token
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_filename> <output_filename>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: Could not open input file %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Error: Could not open output file %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    process_numbers(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Processing complete. Valid numbers have been written to %s\n", argv[2]);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

int isWholeWord(const char *line, const char *match, int matchStart) {
    int matchEnd = matchStart + strlen(match);
    if (matchStart > 0 && !isspace(line[matchStart - 1])) {
        return 0;
    }
    if (line[matchEnd] != '\0' && !isspace(line[matchEnd])) {
        return 0;
    }
    return 1;
}

void replaceWordInLine(const char *line, const char *search, const char *replace, char *result) {
    const char *temp = line;
    char *dest = result;
    int searchLen = strlen(search);
    int replaceLen = strlen(replace);

    while (*temp) {
        const char *match = strstr(temp, search);
        if (match && isWholeWord(temp, search, match - temp)) {
            size_t len = match - temp;
            strncpy(dest, temp, len);
            dest += len;

            strcpy(dest, replace);
            dest += replaceLen;

            temp = match + searchLen;
        } else {
            *dest++ = *temp++;
        }
    }
    *dest = '\0';
}

int main() {
    char filename[256], tempFilename[256] = "tempfile.txt";
    char search[100], replace[100];
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_SIZE], updatedLine[MAX_LINE_SIZE];

    printf("Enter the filename: ");
    scanf("%255s", filename);
    printf("Enter the word to search: ");
    scanf("%99s", search);
    printf("Enter the word to replace: ");
    scanf("%99s", replace);

    inputFile = fopen(filename, "r");
    if (!inputFile) {
        perror("Error opening file");
        return 1;
    }

    outputFile = fopen(tempFilename, "w");
    if (!outputFile) {
        perror("Error creating temporary file");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, inputFile)) {
        replaceWordInLine(line, search, replace, updatedLine);
        fputs(updatedLine, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    if (remove(filename) != 0) {
        perror("Error removing original file");
        return 1;
    }
    if (rename(tempFilename, filename) != 0) {
        perror("Error renaming temporary file");
        return 1;
    }

    printf("Replacement completed successfully.\n");
    return 0;
}

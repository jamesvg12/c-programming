#include <stdio.h>
#include <string.h>

void reverse(char str[]);

int main() {
    char word1[50], word2[50], word3[50];

    printf("Enter the first word: ");
    scanf("%s", word1);

    printf("Enter the second word: ");
    scanf("%s", word2);

    printf("Enter the third word: ");
    scanf("%s", word3);

    printf("\nReversed words:\n");

    printf("First word in reverse: ");
    reverse(word1);

    printf("Second word in reverse: ");
    reverse(word2);

    printf("Third word in reverse: ");
    reverse(word3);

    return 0;
}

void reverse(char str[]) {
    int len = strlen(str);

    for(int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}
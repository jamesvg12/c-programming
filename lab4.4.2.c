#include <stdio.h>
#include <string.h>

void reverseString(char str[], int left, int right) {
    // Base case: when left index is no longer less than right index
    if (left >= right) {
        return;
    }

    // Swap characters at left and right positions
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    // Recursive call to reverse the inner part of the string
    reverseString(str, left + 1, right - 1);
}

int main() {
    char str[100];
    printf("Enter a string to be reversed\n");
    scanf("%[^\n]", str);
    int length = strlen(str);

    reverseString(str, 0, length - 1);
    printf("Reversed string: %s\n", str);

    return 0;
}
// Write a program that requests and stores a sequence of input strings, then prompts the user to enter a suffix to be appended to selected strings.

#include <stdio.h>
#include <string.h>

void addsuffix(char *string, char *suffix, int len1, int len2)
{
    string += len1;
    for (int i = 0; i < len2; i++)
    {
        *string++ = *suffix++;
    }
    *string = '\0';
}

void main()
{
    char a[100], b[100];
    printf("enter string\n");
    scanf("%99s", a);
    int len1 = strlen(a);
    printf("enter suffix\n");
    scanf("%99s", b);
    char *p = a;
    char *q = b;
    int len2 = strlen(b);
    addsuffix(p, q, len1, len2);
    printf("%s", a);
}
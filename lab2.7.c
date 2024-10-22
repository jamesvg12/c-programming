#include <stdio.h>

int main(void)
{
    int input;
    int output = 1;
    printf("Enter the input to the factorial function\n");
    scanf("%d", &input);
    for (int i = 1; i < input + 1; i++)
    {
        output *= i;
    }
    printf("The answer for %d! = %d\n", input, output);
}
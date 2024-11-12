#include <stdio.h>

int main(void)
{
    long num;
    long sum = 0L; /* initialize sum to zero */
    int status = 1;

    printf("Please enter integer to be summed (q to quit): ");

    while (status == 1)
    {
        status = scanf("%ld", &num);
        if (status == 1)
        {
            sum = sum + num;
            printf("Please enter integer to be summed (q to quit): ");
        }
    }
    printf("Those integers sum to %ld.\n", sum);

    return 0;
}

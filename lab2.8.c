#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    double s;
    double output = 0;
    printf("Reimann zeta function\n");
    printf("---------------------\n");
    printf("Enter the value of 'n'\n");
    scanf("%d", &n);
    printf("Enter the value of 's'\n");
    scanf("%lf", &s);
    for (int i = 1; i < n + 1; i++)
    {
        output += 1 / pow(i, s);
    }
    printf("The estimation of the summation of 1/n^%lf for n = %d is %lf\n", s, n, output);
}
#include <stdio.h>
#include <string.h>
#define NUM_EMPLOYEES 10
#define MAX_LENGTH 10

void truncateString(char str[])
{
    if (strlen(str) > MAX_LENGTH)
    {
        str[MAX_LENGTH] = '\0'; // Set the character at index maxLength to null terminator
    }
}

int main()
{

    char name[NUM_EMPLOYEES][MAX_LENGTH + 1], surname[NUM_EMPLOYEES][MAX_LENGTH + 1];
    int age[NUM_EMPLOYEES];
    double monthlysalary[NUM_EMPLOYEES];
    double yearlysalary[NUM_EMPLOYEES];
    int precision;
    char format[50];
    double totalyearly = 0;
    double averageyearly;

    printf("Enter the decimal point limit (0-2)\n");
    scanf("%d", &precision);
    if (precision < 0)
        precision = 0;
    if (precision > 2)
        precision = 2;
    if (precision == 0)
    {
        sprintf(format, "%%-10d %%-20s %%-20s %%-10d $%%-19.0f $%%-19.0f\n");
    }
    if (precision == 1)
    {
        sprintf(format, "%%-10d %%-20s %%-20s %%-10d $%%-19.1f $%%-19.1f\n");
    }
    if (precision == 2)
    {
        sprintf(format, "%%-10d %%-20s %%-20s %%-10d $%%-19.2f $%%-19.2f\n");
    }

    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        printf("Enter the details for employee %d\n", i + 1);
        printf("Enter your name\n");
        scanf("%s", name[i]);
        truncateString(name[i]);
        printf("Enter your surname\n");
        scanf("%s", surname[i]);
        truncateString(surname[i]);
        printf("Enter your age\n");
        scanf("%d", &age[i]);
        printf("Enter your monthly salary\n");
        scanf("%lf", &monthlysalary[i]);
        yearlysalary[i] = monthlysalary[i] * 12;
        printf("\n%-10s %-20s %-20s %-10s %-20s %-20s\n", "Index", "Name", "Surname", "Age", "Salary", "Yearly");
        printf("---------------------------------------------------------------------------------------------------------------\n");
        printf(format, i + 1, name[i], surname[i], age[i], monthlysalary[i], yearlysalary[i]);
    }

    printf("\n%-10s %-20s %-20s %-10s %-20s %-20s\n", "Index", "Name", "Surname", "Age", "Salary", "Yearly");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        printf(format, i + 1, name[i], surname[i], age[i], monthlysalary[i], yearlysalary[i]);
    }

    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        totalyearly+= yearlysalary[i];
    }
    
    averageyearly = totalyearly / NUM_EMPLOYEES;
    printf("\nThe average salary is $%.2f", averageyearly);
}
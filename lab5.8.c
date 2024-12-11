// Write a program that fills an employee (in-memory) database with name, surname, ID, monthly salary, and from which 
// to produce two indexes: one for printing the employee list in ascending order according to their ID, 
// and the other by surname. Test the indexes.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    float salary;
} Employee;

void printEmployees(Employee *employees[], int count);
void sortByID(Employee *employees[], int count);
void sortBySurname(Employee *employees[], int count);

int main() {
    Employee employees[MAX_EMPLOYEES];
    Employee *byID[MAX_EMPLOYEES];
    Employee *bySurname[MAX_EMPLOYEES];
    int count = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &count);
    if (count <= 0 || count > MAX_EMPLOYEES) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Surname: ");
        scanf("%s", employees[i].surname);
        printf("Monthly Salary: ");
        scanf("%f", &employees[i].salary);

        byID[i] = &employees[i];
        bySurname[i] = &employees[i];
    }

    sortByID(byID, count);

    sortBySurname(bySurname, count);

    printf("\nEmployees sorted by ID:\n");
    printEmployees(byID, count);

    printf("\nEmployees sorted by surname:\n");
    printEmployees(bySurname, count);

    return 0;
}

void printEmployees(Employee *employees[], int count) {
    printf("ID\tName\t\tSurname\t\tSalary\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%-10s\t%.2f\n", 
            employees[i]->id, employees[i]->name, employees[i]->surname, employees[i]->salary);
    }
}

void sortByID(Employee *employees[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (employees[i]->id > employees[j]->id) {
                Employee *temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

void sortBySurname(Employee *employees[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(employees[i]->surname, employees[j]->surname) > 0) {
                Employee *temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

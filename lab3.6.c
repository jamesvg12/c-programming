#include <stdio.h>

double calculateTax(double salary, int ifIct, int ifOldElectronic) {
    double firstBracketLimit = ifOldElectronic ? 15000 : 10000;
    double tax = 0;

    if (salary <= firstBracketLimit) {
        tax = salary * 0.18;
    } 
    else if (salary <= firstBracketLimit + 8000) {
        tax = firstBracketLimit * 0.18 + (salary - firstBracketLimit) * 0.20;
    } 
    else {
        tax = firstBracketLimit * 0.18 + 8000 * 0.20 + (salary - firstBracketLimit - 8000) * 0.25;
    }

    if (ifIct) {
        tax *= 0.95;
    }

    return tax;
}

int main() {
    double salary;
    int ifIct = 0, ifOldElectronic = 0;
    char charIfIct, charIfOldElectronic;

    printf("Enter your annual salary: ");
    scanf("%lf", &salary);

    printf("Are you in the ICT Industry? [Y/N]: ");
    scanf(" %c", &charIfIct);

    printf("Do you collect old electronic equipment? [Y/N]: ");
    scanf(" %c", &charIfOldElectronic);

    if (charIfIct == 'Y' || charIfIct == 'y') {
        ifIct = 1;
    }
    if (charIfOldElectronic == 'Y' || charIfOldElectronic == 'y') {
        ifOldElectronic = 1;
    }

    printf("Your tax is: %.2lf\n", calculateTax(salary, ifIct, ifOldElectronic));

    return 0;
}
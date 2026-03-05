#include <stdio.h>

void increment(float *salaries, float *increments, int size) {
    for (int i = 0; i < size; i++) {
        *(salaries + i) += (*(salaries + i) * (*(increments + i) / 100));
    }
}

int main() {
    int numEmployees;
    float salaries[100], increments[100];

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    printf("Enter the salaries of the employees:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Salary of employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("Enter the increment percentages for the employees:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Increment percentage for employee %d: ", i + 1);
        scanf("%f", &increments[i]);
    }

    increment(salaries, increments, numEmployees);

    printf("\nUpdated salaries of the employees:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Updated salary of employee %d: %.2f\n", i + 1, salaries[i]);
    }

    return 0;
}




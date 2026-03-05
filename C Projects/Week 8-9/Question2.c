#include <stdio.h>

float diameter(int *r) {
    return 2.0 * (*r);
}

float circumference(int *r) {
    return 2.0 * 3.14159 * (*r);
}

float area(int *r) {
    return 3.14159 * ((*r) * (*r));
}

int main() {
    int r;
    printf("Enter value for radius: ");
    scanf("%d", &r);

    int *ptrR = &r;

    printf("Calculate:\n(A)rea\n(C)ircumference\n(D)iameter\n\nOption: ");
    char choice;
    scanf(" %c", &choice);

    switch (choice) {
        case 'A':
        case 'a':
            printf("The area of the circle in cm is: %.2f\n", area(ptrR));
            break;
        case 'C':
        case 'c':
            printf("The circumference of the circle in cm is: %.2f\n", circumference(ptrR));
            break;
        case 'D':
        case 'd':
            printf("The diameter of the circle in cm is: %.2f\n", diameter(ptrR));
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
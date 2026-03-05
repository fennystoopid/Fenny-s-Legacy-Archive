#include <stdio.h>

float diameter(float r)
{
    return 2.0 * r;
}

float circumference(float r)
{
    return 2.0 * 3.14159 * r;
}

float area(float r)
{
    return 3.14159 * (r * r);
}

int main() 
{
    float r;
    printf("Enter value for radius: ");
    scanf("%f", &r);

    printf("Calculate:\n(A)rea\n(C)ircumference\n(D)iameter\n\nOption: ");
    char choice;
    scanf(" %c", &choice);
    switch (choice) {
        case 'A':
        case 'a':
            printf("The area of the circle in cm is: %.2f\n", area(r));
            break;
        case 'C':
        case 'c':
            printf("The circumference of the circle in cm is: %.2f\n", circumference(r));
            break;
        case 'D':
        case 'd':
            printf("The diameter of the circle in cm is: %.2f\n", diameter(r));
            break;
        default:
            printf("Invalid choice.\n");
    }
}
#include <stdio.h>


int main() {

    int choice, num1, num2, total, terminate = 0;
    char yesno;

    do {

        printf("Calculator Menu\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n\nEnter yout choice:");
        scanf(" %i", &choice);

        switch(choice){
            case 1:
                printf("Enter two numbers to add:");
                scanf("%i %i", &num1, &num2);
                total = num1 + num2;
                printf("Result: %i + %i = %i", num1, num2, total);
                break;
            case 2:
                printf("Enter two numbers to subtract:");
                scanf("%i %i", &num1, &num2);
                total = num1 - num2;
                printf("Result: %i - %i = %i", num1, num2, total);
                break;
            case 3:
                printf("Enter two numbers to multiply:");
                scanf("%i %i", &num1, &num2);
                total = num1 * num2;
                printf("Result: %i x %i = %i", num1, num2, total);
                break;
            case 4:
                printf("Enter two numbers to divide:");
                scanf("%i %i", &num1, &num2);
                total = num1 / num2;
                printf("Result: %i / %i = %i", num1, num2, total);
                break;
            case 5:
                printf("Calculation ended, thank you.");
                terminate = 1;
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\nDo you want to perform another calculation? (y/n):");
        scanf(" %c", &yesno);
        if (yesno == 'y' || yesno == 'Y') {
            terminate = 0;
        } else {
            terminate = 1;
        }


    } while (terminate == 0);





}
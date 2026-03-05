#include <stdio.h>


int main() {

    int choice, terminate = 0;
    char yesno;
    float reading, cal;

    do {

        printf("\nTemperature Conversion Menu\n1.Fahrenheit --> Celcius\n2.Celcius --> Fahrenheit\n3.Exit\n\nEnter yout choice:");
        scanf(" %i", &choice);

        switch(choice){
            case 1:
                printf("Enter Fahrenheit reading to convert:");
                scanf(" %f", &reading);
                cal = (reading - 32) * 5/9;
                printf("Result: %.2f C", cal);
                break;
            case 2:
                printf("Enter Celcius reading to convert: ");
                scanf(" %f", &reading);
                cal = (reading * 9/5) + 32;
                printf("Result: %.2f F", cal);
                break;
            case 3:
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
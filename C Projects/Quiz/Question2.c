#include <stdio.h>



int main() {
    // Engineering Unit Converter
    int choice, termination = 0;
    char yesno;
    float value, result;

    do {
        // Menu
        printf("\nEngineering Unit Converter\n1. Newton to Pound-force\n2. Pascal to Bar\n3. Joule to Calorie\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        // Choices
        switch(choice) {
            case 1:
                printf("\nEnter force in Newton: ");
                scanf("%f", &value);
                result = value * 0.224809; // Convert Newton to Pound-force
                printf("\nResult: %.2f N = %.2f lbf\n", value, result);
                break;
            case 2:
                printf("\nEnter pressure in Pascal: ");
                scanf("%f", &value);
                result = value * 0.00001; // Convert Pascal to Bar
                 printf("\nResult: %.2f P = %.2f B\n", value, result);
                break;
            case 3:
                printf("\nEnter energy in Joule: ");
                scanf("%f", &value);
                result = value * 0.239006; // Convert Joule to Calorie
                printf("\nResult: %.2f J = %.2f cal\n", value, result);
                break;
            case 4:
                printf("\nProgram terminated. Thank you.\n");
                termination = 1;
                break;
            default:
                printf("\nInvalid choice, try again.\n");
        }

        // Check if user already exitted
        if (termination == 1) {
            break;
        }

        // Ask user if they want to perform another conversion
        printf("\nDo you want to perform another conversion? (y/n): ");
        scanf(" %c", &yesno);
        if (yesno == 'y' || yesno == 'Y') {
            termination = 0;
        } else if (yesno == 'n' || yesno == 'N') {
            termination = 1;
        } else {
            printf("Invalid input, enter (y/n). Continuing...\n");
        }

    } while (termination == 0);


return 0;

}

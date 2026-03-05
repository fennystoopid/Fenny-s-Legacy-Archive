#include <stdio.h>

int main() {

    int condition = 0;
    char letter;

    do {
        printf("Please input a letter between A and E (only in capital): ", letter);

        scanf(" %c", &letter);

        if (letter == 'A'||letter == 'B'||letter == 'C'||letter == 'D'||letter == 'E'){
            condition = 1;
        } else {
            printf("Invalid input, try again.\n");
        }

    } while (condition == 0);  

    printf("The letter you chose is %c.", letter);
}
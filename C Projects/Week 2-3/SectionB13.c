#include <stdio.h>
int quantity;
float price, total;


int main() {

    // Notify user
    printf("Please enter the quantity AND price of item and press Enter: \n");

    // Input
    scanf("%d %f", &quantity, &price);

    // Calc
    total = quantity * price;

    // Output
    printf("Your total is RM%.2f. Thank you.", total);

    return 0;
}
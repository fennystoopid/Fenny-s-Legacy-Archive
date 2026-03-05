#include <stdio.h>

int main() 
{
    float orderprice, amountdue;
    int numofdays;
	printf("Enter order amount RM: ");
	scanf("%f", &orderprice);
    printf("Enter number of day after invoice issue date: ");
	scanf("%d", &numofdays);

	if (numofdays <= 10) {
        if (orderprice > 1000) {
            amountdue = orderprice - ((orderprice) * 0.04);

        } else if (orderprice > 500 && orderprice < 1000) {
            amountdue = orderprice - ((orderprice) * 0.02);

        } else if (orderprice < 500) {
            amountdue = orderprice;

        }
    } else {
        amountdue = orderprice;
    }

    printf("Amount due RM : %.2f", amountdue);

}
#include <stdio.h>

int main() {

    int num, total, howmany = 0;

    do {

        printf("Input a number, this will be added until sum becomes more than 100: ");
        scanf(" %i", &num);

        total += num;
        howmany += 1;


    } while (total <= 100);

    printf("Your final sum is %i. You inputted %i times.", total, howmany);
}
#include <stdio.h>

int main() {

    int num, i;

    printf("Insert a positive integer: ");
    scanf("%i", &num);
    
    /// if number less than or equal to one, it is not a prime number.
    if (num <= 1) {
        printf("This is not a prime number");
    }

    /// if number is divisible by 2 and the number is more than 2, not a prime number.
    if (num % 2 == 0 && num > 2) {
        printf("This is not a prime number");
    }

    ///checks for all possible divisible numbers.. starting from 3 until the number divided by 2.
    for(i = 3; i < num / 2; i+= 2) {
        if (num % i == 0) {
            printf("This is not a prime number");
        }
    }
    printf("This is a prime number");
    
}
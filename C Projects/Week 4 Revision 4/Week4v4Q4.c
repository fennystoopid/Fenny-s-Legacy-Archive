#include <stdio.h>

int main() {

    int n, i, sum = 0, terminate = 0;

    do
    {
        printf("Input a positive integer: ");
        scanf(" %i", &n);
        for (i = 2; i < n; i+=2) {
            sum += i;
        }
        terminate = 1;
    } while (terminate == 0);
    
    printf("The sum of all even numbers of %i is %i.", n, sum);
}
#include <stdio.h>

int main() {

    int num, totalnum, i = 1, n;

    printf("How many times you wanna sum?: ");
    scanf("%i", &n);

    while (i <= n){
        printf("Input the %i of the numbers, only integers: ", i);
        scanf("%i", &num);
        totalnum += num;
        i++; 
    }

    printf("The total of all those integers is %i", totalnum);
}
#include <stdio.h>

int main() {

    int numbers[10], i, num = 0, even = 0, odd = 0;

    printf("Key in 10 numbers: ");
    do {
        scanf("%i", &numbers[num++]);

    } while (getchar() != '\n' && num < 10);
    

    for (i = 0; i < 10;i++) {

        if (numbers[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }

    }

    printf("The total number of even numbers entered are : %i\n", even);
    printf("The total number of odd numbers entered are : %i\n", odd);

}
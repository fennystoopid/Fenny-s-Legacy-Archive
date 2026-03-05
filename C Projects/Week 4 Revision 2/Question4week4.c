#include <stdio.h>

int main() {

    int multiple, i = 1, n;

    printf("How big multiplication table you wanna make: ");
    scanf(" %i", &n);

    while(i <= n){
        multiple = i * 5;
        printf("%i X 5 = %i\n", i,multiple);
        i++;
    }



}
#include <stdio.h>

int main() {

    int num, i = 1, largest;

    while (i < 6){
        printf("Number %i: ", i);
        scanf(" %i", &num);

        if (num >= largest){
            largest = num;
        } else if (i == 1) {
            largest = num;
        }
        i++; 
    }
    printf("The largest is: %i", largest);

}
#include <stdio.h>

int main() {

    int A[5], i;

    printf("Enter the values of an Array:");

    for (i = 0; i < 5;i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < 5;i++) {
        printf("%d", A[i]);
    }

}
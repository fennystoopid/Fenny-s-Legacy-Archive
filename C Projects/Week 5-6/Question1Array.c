#include <stdio.h>

int main() {

    int i, Marks[100], num, calculation = 0;
    float final;
    printf("Enter the number of subjects: ");
    scanf("%i", &num);

    for (i = 1; i <= num;i++) {
        printf("Subject %i: ", i);
        scanf("%d", &Marks[i]);
    }

    for (i = 1; i <= num;i++) {
        calculation += Marks[i];
    }

    final = (float)calculation / num;
    printf("Average marks is %.2f", final);
}
#include <stdio.h>

int main() {

    int grade;
    printf("Enter your grade:");
    scanf("%d", &grade);
    if (grade >= 60) {
        printf("Passed\n");
        printf("%d is your grade.", grade);
    }
    else
        printf("Fail");
    return 0;

}
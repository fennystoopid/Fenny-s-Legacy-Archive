#include <stdio.h>

int main() 
{
    int num1, num2;
	printf("Enter Number 1: ");
	scanf("%d",&num1);
    printf("Enter Number 2: ");
	scanf("%d",&num2);
	if (num1 > num2) {
        printf("%d is greater than %d.", num1, num2);
    } else if (num1 < num2) {
        printf("%d is greater than %d.", num2, num1);
    }

}
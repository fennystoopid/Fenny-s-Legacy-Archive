#include <stdio.h>

int main() 
{
    int num1;
	printf("Enter Number: ");
	scanf("%d",&num1);
	if (num1 % 2 == 1) {
        printf("%d is an odd value.", num1);
    } else if (num1 % 2 == 0) {
        printf("%d is an even value.", num1);
    }
}
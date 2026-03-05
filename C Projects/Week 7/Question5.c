#include <stdio.h>

int base, exponent;

int rec(int n)
{
    int sum = 1;

    //Base condition to stop recursion
    if (n == exponent){
        return sum;
    }

    //Recursion
    sum *= base;

    //to start it up again
    return sum * rec(n + 1);
}

int main() 
{
    printf("Enter base value: ");
    scanf("%d", &base);
    printf("Enter exponent value: ");
    scanf("%d", &exponent);
    printf("%d to the power of %d is %d\n", base, exponent, rec(0));
}
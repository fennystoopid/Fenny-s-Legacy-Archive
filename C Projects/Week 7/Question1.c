#include <stdio.h>

int num;

int reverseDigit(int n) 
{
    int reversed = 0;
    while (n > 0) 
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() 
{
 
    printf("Enter a number between 1 and 9999: ");
    scanf("%d", &num);

    reverseDigit(num);
    printf("The number %d with its digits reversed is: %d\n", num, reverseDigit(num));

}
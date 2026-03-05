#include <stdio.h>
// the “int” indicate this main function will return numeric number
int main() {
    int num1, num2, sum;
    // Asking for input
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    // Calculating the sum
    sum = num1 + num2;
    // Printing the result
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    return 0;     // to indicate the program has executed successfully and return a result
}

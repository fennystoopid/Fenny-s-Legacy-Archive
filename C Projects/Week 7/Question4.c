#include <stdio.h>


int num;

int rec(int n)
{

    int sum = 1;

    //Base condition to stop recursion
    if (n == num){
        return sum;
    }

    //Recursion
    sum *= (n + 1);

    //to start it up again
    return sum * rec(n + 1);
}


int main() 
{

    printf("Enter an integer: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("The factorial of a negative number is not defined in mathematics.\n");
        return 1;
    }

    printf("%d! = %d\n", num, rec(1));
}
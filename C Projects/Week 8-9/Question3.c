#include <stdio.h>

//Declare temporary storage globally
int tempstore;

int swap (int *a, int *b)
{
    //Store address of A in temporary storage
    tempstore = *a;
    //Address of A is now equal to address of B
    *a = *b;
    //Tempstore containing previous address of A is now address of B
    *b = tempstore;
}

int main() 
{

    int num1, num2;

    printf("Input your first num: ");
    scanf("%d", &num1);

    printf("Input your second num: ");
    scanf("%d", &num2);

    printf("\n[Before Value]\n Number 1 = %d\n Number 2 = %d\n", num1, num2);
    printf("\n[Before Address]\n Number 1 = %p\n Number 2 = %p\n", &num1, &num2);

    swap(&num1, &num2);

    printf("\n[After Value]\n Number 1 = %d\n Number 2 = %d\n", num1, num2);
     printf("\n[After Address]\n Number 1 = %p\n Number 2 = %p\n", &num1, &num2);

}


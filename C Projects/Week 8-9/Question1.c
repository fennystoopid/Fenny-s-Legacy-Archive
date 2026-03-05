#include <stdio.h>

int main() {

    //Declare a pointer and integer
    int Example = 10;
    int* ptr = &Example;

    printf("\nThe current address of Example is %p", &Example);
    printf("\nThe current value of Example is %d", Example);

    //Declare pointer to an integer
    ptr = &Example;

    //Use pointer to modify value of variable
    *ptr = 20;

    printf("\nThe modified address of Example is now %p", &Example);
    printf("\nThe modified value of Example is now %d", Example);

}
#include<stdio.h>
void main() 
{	
    int a, *aPtr;
    a=100;
    aPtr=&a;
    printf("\n The address of a is %p", &a);
    printf("\n The value contained in aPtr is %p", aPtr);
    printf("\n The value of a %d and de-referencing aPtr %d returns the same value", a,*aPtr); 
}

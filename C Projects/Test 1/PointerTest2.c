#include<stdio.h>
void main()
{
    char var='X'; // var a character variable, is declared and initialized to ‘X’
    char *charPtr; //charPtr a pointer to a character is declared
    charPtr=&var; //charPtr now holds (points to) the address of var 
    *charPtr='Y'; //The value which charPtr points to, is now changed to ‘Y’. using * in this manner is called dereferencing a pointer
    printf("\n Value of var now is : %c",var); // displays new value ‘Y’
}

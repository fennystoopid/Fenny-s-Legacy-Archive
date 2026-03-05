#include <stdio.h>

/* To find odd or even*/
int main()
{ int n;
  printf("Input a number:");
  scanf("%d", &n);
  switch(n%2){
    case 0 :
      printf("Even Number");break;
    case 1:
        printf("Odd Number");break;
}}

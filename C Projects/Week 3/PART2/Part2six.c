#include <stdio.h>

int main() 
{
    int choice;

    printf(" Menu\n-----------\n1 C\n2 Java\n3 VB.Net\n>");
	scanf("%d", &choice);

    switch (choice) {
        case 1 :
            printf ("My favourite programming language is: C\n");
            break;
        case 2 :
            printf ("My favourite programming language is: Java\n");
            break;
        case 3 :
            printf ("My favourite programming language is: VB.Net\n");
            break;
        default :
            printf ("I do not have any favourite programming language.\n");
            break;
    }
}
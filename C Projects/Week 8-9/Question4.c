#include <stdio.h>

//Declare list, (i,j) for loop and n for number of elements in list
int *a[100], i, j, n;

//Declare sort function
void sort();

//Main Function
int main() 
{

    //Input the number of elements
    printf("Enter the number of elements in the list/array: ");
    scanf("%i", &n);

    //Input the elements in the list
    printf("\nEnter %d numbers in the array: \n", n);
    for (int i=0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    //call the sort function
    sort();

    printf("\nSorted elements are:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void sort()
{
    //Declare swap condition and temporary pointer
    int swap = 1, *temppointer;

    //BUBBLE SORT
    //set so that first for loop (i) runs if i less than number of element and swap condition is 1
    for(i = 0; i < n && swap == 1; i++) 
    {
        //swap condition is 0, disable first for loop
        swap = 0;

        //second for loop (j)
        for (j = 0; j < n - (i + 1); j++)
        {
            temppointer = a[j];
            a[j] = a[j+1];
            a[j+1] = temppointer;
            swap = 1;
        }

    }
}

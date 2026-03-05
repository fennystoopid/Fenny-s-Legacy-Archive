#include<stdio.h>
int* check (int); 	//function prototype

void main()  {
 	int *ptr, a=1000;	//Declare ptr and a, assign 1000 to a
	ptr=check(a);	//Function call
	printf("\n Value returned is %d\n", *ptr);	// *ptr is 0
}

int* check (int x) {	
	//function header
	if (x<=1000)		
		x=0;
	return (&x);
}


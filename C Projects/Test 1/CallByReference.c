#include<stdio.h>
void callbyreference(int *);	//function prototype
void main(){
	int num;		//Declaring integer variable num
	printf("\n Enter a value: "); 
	scanf("%d",&num);	//Accept the value from the user
	callbyreference(&num);	//Function call sending address of num
	printf("\n Value of num is %d",num);	
}
void callbyreference (int *b){	//function header
	*b=*b+100;		//Value pointed to by b is increased by 100 
}

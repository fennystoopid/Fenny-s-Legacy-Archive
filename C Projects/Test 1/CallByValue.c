#include<stdio.h>
void callbyvalue(int);		//function prototype
void main(){
	int num;			//Declaring integer variable num
	printf("\n Enter a value: "); 
	scanf("%d",&num);		//Accept the value from the user
	callbyvalue(num);		//Function call sending value of num
	printf("\n Value of num is %d",num);	
}
void callbyvalue (int b) {	//Parameter b is a mirror image of num
	b=b+100;			//b is increased by 100 
}

//Value remains unchanged

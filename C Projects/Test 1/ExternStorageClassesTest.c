#include<stdio.h>

extern int a = 1, b = 2, c = 3;

int f(void);

int main(){	
    printf("%3d\n", f());
	printf("%3d%3d%3d\n", a, b, c);
	return 0;
}

int f(void){
	int b, c;
	a=b=c=4;
	return (a + b + c);
}

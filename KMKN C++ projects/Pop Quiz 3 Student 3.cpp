#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main(){
	
	float pmreceived , foodspent, transspent, othersspent, savings, foodper = 60, transper = 25, otherper = 10, savinper = 5;
	
	cout << "Please enter your pocket money received this month \nRM";
    cin >> pmreceived;
	
	foodspent = pmreceived * (foodper / 100);
	transspent = pmreceived * (transper / 100);
	othersspent = pmreceived * (otherper / 100);
	savings = pmreceived * (savinper / 100);
	
	cout << "\n-----------SPENDING LIST-----------\nPocket Money: RM";
	printf("%.2f", pmreceived);
	
	cout << "\n1) Food Spent: RM";
	printf("%.2f", foodspent);
	
	cout << "\n2) Transportation Spent: RM";
	printf("%.2f", transspent);
	
	cout << "\n3) Others Spent: RM";
	printf("%.2f", othersspent);
	
	cout << "\n4) Savings: RM";
	printf("%.2f", savings);
	cout << "\n";
	
	system ("PAUSE");
    return 0; 

}

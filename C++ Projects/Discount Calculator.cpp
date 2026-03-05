#include <iostream>

using namespace std;

int main() {
	
	float cashbal, totalamount, shopdis, finalcashbal, discount, finalTA;
	
	cout << "Please insert your current cash balance : RM";
	cin >> cashbal;
	cout << "Please insert total item price amount : RM";
	cin >> totalamount;	
	cout << "Please insert your shop discount received (%) : ";
	cin >> shopdis;
	
	discount = totalamount * (shopdis/100);
	finalTA = totalamount - discount;
	finalcashbal = cashbal - finalTA;
	
	cout << "\n" << "RM" << finalcashbal << " is your remaining cash balance. Thank you!" << "\n";
    return 0;
	
}


#include <iostream>

using namespace std;

int main() {
	
	string SN1, SN2, SN3, SC1, SC2, SC3, SCN1, SCN2, SCN3;
	int totalstud = 3;
	float SW1, SW2, SW3, average;
	char SG1, SG2, SG3;
	
	cout << "STUDENT 1 DETAILS\n" << "Name : ";
	cin >> SN1;
	cout << "Class : ";
	cin >> SC1;
	cout << "Gender (M or F) : ";
	cin >> SG1;
	cout << "College Number : ";
	cin >> SCN1;
	cout << "Weight : ";
	cin >> SW1;
	
	cout << "\nSTUDENT 2 DETAILS\n" << "Name : ";
	cin >> SN2;
	cout << "Class : ";
	cin >> SC2;
	cout << "Gender (M or F) : ";
	cin >> SG2;
	cout << "College Number : ";
	cin >> SCN2;
	cout << "Weight : ";
	cin >> SW2;
	
	cout << "\nSTUDENT 3 DETAILS\n" << "Name : ";
	cin >> SN3;
	cout << "Class : ";
	cin >> SC3;
	cout << "Gender (M or F) : ";
	cin >> SG3;
	cout << "College Number : ";
	cin >> SCN3;
	cout << "Weight : ";
	cin >> SW3;
	
	average = (SW1, SW2, SW3) / totalstud;
	
	cout << "\n" << "STUDENT DATA:";
	cout << "\n*" << SN1 << " from class " << SC1;
	cout << "\n*" << SN2 << " from class " << SC2;
	cout << "\n*" << SN3 << " from class " << SC3;
	cout << "\n\n" << "AVERAGE WEIGHT:";
	cout << "\n" << average << " is the weight average of " << totalstud << " students." << "\n";
    return 0;
	
}	

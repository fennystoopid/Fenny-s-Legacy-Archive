#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main() 	{
	
	string StudName, StudClass, Status, Gender;
	float BMIFINAL, StudHeight, StudWeight;
	char StudGender;
	
	cout << "Enter Name : ";
    getline(cin, StudName);
    cout << "Enter Class : ";
    cin >> StudClass;  // :3
    cout << "Enter Gender (F/M) : ";
    cin >> StudGender;
	cout << "Enter Student's Height (in metres) : ";
    cin >> StudHeight;
	cout << "Enter Student's Weight (in kilograms) : ";
    cin >> StudWeight;
	
	BMIFINAL = StudWeight / pow(StudHeight,2);
	
	if (BMIFINAL < 18.5) {
    	    Status = "UnderWeight";
     } else if (BMIFINAL >= 18.5 && BMIFINAL <= 24.9) {	   
            Status = "Normal";
     } else if (BMIFINAL >= 25 && BMIFINAL <= 29.9) {	   
            Status = "OverWeight";
     } else if (BMIFINAL >= 30) {	   
            Status = "Obese";
	 } else {
            Status= "Assumed as ERROR (No data or no matching data provided)";       
     }
	
	if (StudGender == 'M' || StudGender == 'm') {
		Gender = "Male";
	} else if (StudGender == 'F' || StudGender == 'f') {
		Gender = "Female";
	} else {
		Gender = "I assume you gay or something idk bro";
	}
	
	
	
	
	
	 //OUTPUTT
      cout << "\n*********BMI DATA********";
      cout << "\nName : " << StudName;
      cout << "\nClass : " << StudClass;
      cout << "\nGender : " << Gender;
      cout << "\nBMI : ";
      printf("%.2f", BMIFINAL);
      cout << "\nStatus : " << Status << "\n";
      system ("PAUSE");
      return 0; 
      
}

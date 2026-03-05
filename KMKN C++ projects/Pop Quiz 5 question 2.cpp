#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main() 	{
	
	string NameOwner, DogOrCat;
	char Pet_Type;
	int Numof_Days;
	float Pet_Weight, Final_Price;
	
	cout << "Enter Name : ";
    getline(cin, NameOwner);
    cout << "Enter Pet Type (C for Cat, D for Dog) : ";
    cin >> Pet_Type;
	cout << "Enter Number of Days : ";
    cin >> Numof_Days;
	cout << "Enter Pet's Weight (in kilograms) : ";
    cin >> Pet_Weight;
	
	
	if ( Pet_Type == 'c' || Pet_Type == 'C' ) {
		DogOrCat = "Cat";
		
		if ( Pet_Weight <= 3.0 ) {
			Final_Price = 20.50 * Numof_Days;
		} else if ( Pet_Weight > 3.0) {
			Final_Price = 40.50 * Numof_Days;
		}
	}
		
	else if ( Pet_Type == 'd' || Pet_Type == 'D' ) {
		DogOrCat = "Dog";
		
		if ( Pet_Weight < 4.0 ) {
			Final_Price = 50.50 * Numof_Days;
		} else if ( Pet_Weight >= 4.0 && Pet_Weight <= 6.0 ) {
			Final_Price = 40.50 * Numof_Days;
		} else if ( Pet_Weight > 6.0 ) {
			Final_Price = 80.50;
		}


    } else {
    	DogOrCat = "Error, please insert valid data type";
    	Final_Price = 0;
    	cout << "\n ERROR!! DATA TYPE INVALID!!\n";	
    }

	
	//OUTPUTT
      cout << "\n*********ZAFRI's PET STORE********";
      cout << "\nOwner's Name : " << NameOwner;
      cout << "\nPet Type : " << DogOrCat;
      cout << "\nNumber Of Days : " << Numof_Days;
      cout << "\nPet Weight : " << Pet_Weight << "KG";
      cout << "\nPrice : RM" << Final_Price;
      cout << "\n";
      system ("PAUSE");
      return 0; 
	
	
}

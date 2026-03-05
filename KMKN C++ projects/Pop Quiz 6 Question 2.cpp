#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main() 	{
	
	char Volume_Select;
	string Cal_Type;
	float lengthin, radiusin, heightin, final_ans, Pie = M_PI;
	
	cout << "—-------------------------------------------------\n\tWELCOME TO VOLUME CALCULATOR\n—-------------------------------------------------\n";
	cout << "\tMenu to Calculate : \n\tA) Volume of sphere\n\tB) Volume of cylinder\n\tC) Volume of cube\n—--------------------------------------------------\n";
	cout << "\n Enter your option (A , B or C) : ";
	cin >> Volume_Select;
	cout << "\n—-------------------------------------------------";
	
	if ( Volume_Select == 'a' || Volume_Select == 'A' ) {
		cout << "\n\nPlease insert radius of sphere (in centimetres) : ";
		cin >> radiusin;
		final_ans = (4/3) * Pie * pow(radiusin, 3);
		Cal_Type = "Sphere";
	}
		
	else if ( Volume_Select == 'b' || Volume_Select == 'B' ) {
		cout << "\n\nPlease insert radius and height of cylinder (IN ORDER and in centimetres) : ";
		cin >> radiusin;
		cin >> heightin;
		final_ans = Pie * pow(radiusin, 2) * heightin;
		Cal_Type = "Cylinder";
    }
	
	else if ( Volume_Select == 'c' || Volume_Select == 'C' ) {
		cout << "\n\nPlease insert length of cube (in centimetres) : ";
		cin >> lengthin;
		final_ans = pow(radiusin, 3);
		Cal_Type = "Cube";
    }
	
	else {
		Cal_Type = "ERROR";
	}
	
	
	
	if ( Cal_Type == "Cube" ) {
		cout << "\n\n—-------------------------------------------------";
		cout << "\nYour answer for cube volume is : " << final_ans << "CM^3\n";
		cout << "—-------------------------------------------------\n";
	}
	else if ( Cal_Type == "Cylinder" ) {
		cout << "\n\n—-------------------------------------------------";
		cout << "\nYour answer for cylinder volume is : " << final_ans << "CM^3\n";
		cout << "—-------------------------------------------------\n";
	}
	else if ( Cal_Type == "Sphere" ) {
		cout << "\n\n—-------------------------------------------------";
		cout << "\nYour answer for sphere volume is : " << final_ans << "CM^3\n";
		cout << "—-------------------------------------------------\n";
	}
	else {
		cout << "\n\n—-------------------------------------------------";
		cout << "\nERROR! Invalid Data Values Detected! Please Try Again!\n";
		cout << "—-------------------------------------------------\n";
		return 0;
	}
	
	system ("PAUSE");
	return 0;
}

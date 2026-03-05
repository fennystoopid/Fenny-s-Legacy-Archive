#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//declare global variable
string company;
int year=0, Female=0, Male=0;

//declare array
string stafname []={1};
string gender []={1};
float salary1[]={1};
float salary2[]={1};
int month[]={1};

//put function here
float calculation1(float rm, int unit){
    rm=rm*unit;
    return(rm);
}

//main function 
int main(){  //Start main

    // declare local variables
    int counter=0,numofstaf=0;
    float TOTALSALARYTOPAY=0;
    
        cout<<"COMPANY NAME : ";
        cin>>company;
        
        cout<<"YEAR : ";
        cin>>year;
        
        cout<<"HOW MANY STAF:";
        cin>> numofstaf;
        
        //Loop A: while loop to input data into array
        counter=0;
        while (counter < numofstaf) {
            
            //process to input data into array
            cout << "\nStaf " << (counter+1) <<endl; 
            

            cout << "\tName : ";
            cin  >> stafname[counter];
            
            cout << "\tSalary Per Month : ";
            cin  >> salary1[counter];
            
            cout << "\tTotal Month Work : ";
            cin  >> month[counter];

repeat_gender:
cout << "\tGender : ";
            cin  >> gender[counter];

		if (gender[counter] == "f" or gender[counter] == "F") {
			Female++;
		} if (gender[counter] == "m" or gender[counter] == "M") {
			Male++;
		} else {
			cout<<"Error, please enter only f/F for Female or ";
			cout <<"m/M for Male.\n";
			goto repeat_gender;
		}
            
            salary2[counter] = calculation1(salary1[counter],month[counter]);
            
//to collect TOTALSALARYTOPAY value of every staff in the company
            TOTALSALARYTOPAY = TOTALSALARYTOPAY + salary2[counter];
            
            counter++;

        } // close Loop A

        //to clear the screen
        system ("CLS");
        
        //make table header
        cout << endl << endl;
        cout << "COMPANY NAME \t: " << company <<endl;
        cout << "YEAR \t\t: " << year << endl << endl;
        cout << "Number \tStaf Name\tSalary\tMonth\tTotal Salary\t";
        cout << endl ;

        //Loop B: do while loop to output data from array to screen 
        counter=0;
        do{ //output data from array into a table   
            
            cout << (counter+1) ;
            cout << "\t"<< stafname[counter];
            cout << "\t\t"<< salary1[counter];
            cout << "\t\t"<< month[counter];
            cout << "\t\t"<< salary2[counter];
            cout << "\n";
            counter++;
        }while (counter < numofstaf); //close Loop B

        cout << "\nTOTAL SALARY TO PAY RM: "<< TOTALSALARYTOPAY <<endl<<endl;


		cout << "DO YOU WANT TO CONTINUE WITH OTHER COMPANY : (YES/NO) ";
		cin >> sentinel;
		} while (sentinel == "YES");
return 0;
} // close main




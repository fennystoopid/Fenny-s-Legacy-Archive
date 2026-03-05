#include <iostream>
#include <ios>  
#include <limits> 

using namespace std;

char loop = 'y';
int aircraftcode;

int OptionMenu(){
	system ("Color 0A");
	system ("cls");
	cout << "";
	
	// Input
	cout << "Insert code to check aircraft system: ";
	cin >> aircraftcode; 
	
	// ignore buffer
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  	// Clear input buffer
  	cin.clear();
  	cin.sync();
  	
    return (aircraftcode);	
}

void LoopConfirm(){
	// Input
	cout << "\nDo you want to continue checking for another code? (Y/N) : ";
	cin >> loop;
	
	// ignore buffer
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  	// Clear input buffer
  	cin.clear();
  	cin.sync();	
  	
}

int main () {
	
	do{
		aircraftcode=OptionMenu();
		// Process
		switch (aircraftcode) {
	 	
	 		// Option 1
        	case 100: {
				system ("cls");
				cout << "Normal speed range: Aircraft is in optimal speed";
				LoopConfirm();
            
            break;
    		}
			// Option 2    
        	case 101:{
        		system ("cls");
        		cout << "Over-speed warning: Aircraft is overspeeding";
        		LoopConfirm();
        		
            break;
    		}
			// Option 3  
        	case 88:{
            	system ("cls");
            	cout << "Low Oil Pressure";
            	LoopConfirm();
            	
            break;
    		} 
    		//option 4
    		case 187:{
        		system ("cls");
        		cout << "Engine Failure";
        		LoopConfirm();

            break;
    		}
			// selector doesnt match any valid numbers   
        	default:{
        		system ("cls");
        		cout << "Error! Code entered is either not available or does not exist!\n";
        		system ("PAUSE");
        		main();
            break;
    		}
    	}
	} while (loop == 'Y' | loop == 'y');
	
	system ("cls");
	cout << "Thank you for using Aircraft Maintenance System";
	return 0;	
}

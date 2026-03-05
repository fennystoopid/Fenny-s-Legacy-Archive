#include <iostream>
#include <cmath>
// used to get stream size 
#include <ios> 
// used to get numeric limits 
#include <limits> 
#include <windows.h>
#include <stdlib.h>

using namespace std;

char selector, confirm; 
float input_money = 0, bal = 0;

int mainmenu() {
	// Menu
	system ("Color 0B");
	system ("cls");
	cout << "\n****************STEAM-SALE*******************" << "\nCurrent cheapest games up for grabs!!";
	cout << "\n\n[1] Need For Speed Heat Deluxe Edition" << "\n[2] Max Payne 3" << "\n[3] The Escapists 2\n";
	cout << "\n*********************************************";
	
	// Input
	cout << "\nPlease select an option you like to purchase (Input n to quit): ";
	selector = cin.get();//cin >> selector;
	
	// clear buffer before taking 
    // new line 
    cin.ignore(1,'\n');
    return (selector);
}

void calculation(float, float, float);

int Gameprinter(float agp, float dis, float tad, string type){
	system ("cls");
    
	if (type == "NFSHEAT") {
		cout << "-----------------------------------------------------------------------\n";
    	cout << "\tYou choose Need For Speed Heat Deluxe Edition!";
    	cout << "\n\n\tA thrilling race experience pits you\n\tagainst a city's rogue police force as you\n\tbattle your way, into street racing's elite.";
    	cout << "\n\n\tThe Deluxe Edition comes with:-\n\t [] K.S Edition Mitsubishi Lancer Evolution X\n\t [] 3 additional K.S Edition cars\n\t [] 4 exclusive character outfits\n\n";	
	}	if (type == "MAXPAYNE3") {
		cout << "-----------------------------------------------------------------------\n";
    	cout << "\tYou choose Max Payne 3!";
    	cout << "\n\n\tCombining cutting edge shooting mechanics\n\twith a dark and twisted story, Max Payne 3\n\tis a seamless, highly detailed,\n\tcinematic experience from Rockstar Games.";
    	cout << "\n\n\tThis complete edition of Max Payne 3 includes:-\n\t [] The complete original game\n\t [] Deathmatch Made In Heaven DLC\n\t [] Painful Memories Pack DLC\n\t [] Silent Killer Loadout Pack DLC\n\n";
    	cout << "-----------------------------------------------------------------------\n";
	}	if (type == "ESCAPIST2") {
		cout << "-----------------------------------------------------------------------\n";
    	cout << "\tYou choose The Escapists 2!";
    	cout << "\n\n\tRisk it all to breakout\n\tfrom the toughest prisons in the world.\n\tExplore the biggest prisons yet,\n\twith multiple floors, roofs, vents and underground tunnels.";
    	cout << "\n\n\tThe games includes multiple features! such as:-\n\t [] 11 Prisons\n\t [] Up to 4 player co-operative and versus multiplayer\n\t [] Over 300 customisations\n\t [] Prison Map Editor\n\n";
    	cout << "-----------------------------------------------------------------------\n";
	}
    
	cout << "\tThe game's original price is RM" << agp << "\n\tand the game is on discount around " << dis << "%!";
    cout << "\n-----------------------------------------------------------------------\n";
    cout << "\n\nThe game's price after discount is now RM" << tad << "!\n";
}

int main () {
	
	selector=mainmenu();
	
	// Process
	switch (selector) {
	 	
	 	// Option 1
        case '1': {
		
    		Gameprinter(299.0, 95.0, 14.95, "NFSHEAT");
            
            calculation(299.0, 95.0, 14.95);
            
            break;
    	}
		// Option 2    
        case '2':{
        	
        	Gameprinter(59.0, 70.0, 17.7, "MAXPAYNE3");
            
            calculation(59.0, 70.0, 17.7);
			
            break;
    	}
		// Option 3  
        case '3':{
            
            Gameprinter(69.0, 75.0, 17.25, "ESCAPIST2");
            
            calculation(69.0, 75.0, 17.25);
			
            break;
    	}
        case 'n':{
        	system ("cls");
        	cout << "You have requested to exit..";
        	getchar();
        	goto exit_loop;
            break;
    	}
		// selector doesnt match any valid numbers   
        default:{
			system ("cls");
            cout << "Error! Choosen option is either not available or does not exist!\n\n";
            getchar();
            main();
            break;
    	}
    }

	exit_loop:
	system ("cls");
	cout << "\n\n--------------END OF PROGRAM, THANKS FOR BROWSING!--------------\n\n";
	getchar();
	return 0;
	
}

void calculation(float price, float discountz, float actualprice) {
    		
	cout << "\nConfirm purchase? (Y/N): ";
    cin >> confirm;
    cin.ignore(1,'\n');
            
    if (confirm == 'Y'||confirm == 'y'){
        cout << "\nPlease insert the amount of money you paid: ";
        cin >> input_money;
        cin.ignore(1,'\n');
        
        if (input_money > actualprice) {
        	system ("cls");
            bal = input_money - actualprice;
        	cout << "Success! You now have RM" << bal << " left!";
		} else {
			system ("cls");
			bal = actualprice - input_money;
			cout << "Error! Not enough money to pay for the game! You need RM" << bal << " more!\n";
			getchar();
			main();
		}	
		} else {
			system ("cls");
			cout << "You have cancelled your purchase, returning to main menu..\n";
			getchar();
			main();
		}
}

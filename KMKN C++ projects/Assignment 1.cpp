#include <iostream>
#include <cmath>
// used to get stream size 
#include <ios> 
// used to get numeric limits 
#include <limits> 
#include <windows.h>
#include <stdlib.h>

using namespace std;

int main () {
	
	char selector, confirm; 
	float dis_deduce = 0, input_money = 0, bal = 0, totalafter_dis = 0, actualgame_price = 0, discount = 0;
	
	// Menu
	start:
	system ("Color 0B");
	system ("cls");
	cout << "\n****************STEAM-SALE*******************" << "\nCurrent cheapest games up for grabs!!";
	cout << "\n\n[1] Need For Speed Heat Deluxe Edition" << "\n[2] Max Payne 3" << "\n[3] The Escapists 2\n";
	cout << "\n*********************************************";
	
	// Input
	cout << "\nPlease select an option you like to purchase: ";
	cin >> selector;
	
	// clear buffer before taking 
    // new line 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	
	// Process
	 switch (selector) {
	 	
	 	// Option 1
        case '1':
        	system ("cls");
        	system ("Color 81");
        	actualgame_price = 299.0;
        	discount = 95.0;
            dis_deduce = actualgame_price * (discount/100);
            totalafter_dis = actualgame_price - dis_deduce;
            
            cout << "-----------------------------------------------------------------------\n";
        	cout << "\tYou choose Need For Speed Heat Deluxe Edition!";
            cout << "\n\n\tA thrilling race experience pits you\n\tagainst a city's rogue police force as you\n\tbattle your way, into street racing's elite.";
            cout << "\n\n\tThe Deluxe Edition comes with:-\n\t [] K.S Edition Mitsubishi Lancer Evolution X\n\t [] 3 additional K.S Edition cars\n\t [] 4 exclusive character outfits\n\n";
            cout << "-----------------------------------------------------------------------\n";
            cout << "\tThe game's original price is RM" << actualgame_price << "\n\tand the game is on discount around " << discount << "%!";
            cout << "\n-----------------------------------------------------------------------\n";
            cout << "\n\nThe game's price after discount is now RM" << totalafter_dis << "!\n";
            
            cout << "\nConfirm purchase? (Y/N): ";
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (confirm == 'Y'||confirm == 'y'){
            	cout << "\nPlease insert the amount of money you paid: ";
            	cin >> input_money;
            	if (input_money > totalafter_dis) {
            		system ("cls");
            		bal = input_money - totalafter_dis;
            		cout << "Success! You now have RM" << bal << " left!";
			    } else {
					system ("cls");
					bal = totalafter_dis - input_money;
					cout << "Error! Not enough money to pay for the game! You need RM" << bal << " more!";
			    }	
			} else {
				system ("cls");
				cout << "You have cancelled your purchase, returning to main menu..\n";
				system ("PAUSE");
                goto start;
			}
            
            break;
        
		// Option 2    
        case '2':
        	system ("cls");
        	system ("Color 84");
        	actualgame_price = 59.0;
        	discount = 70.0;
            dis_deduce = actualgame_price * (discount/100);
            totalafter_dis = actualgame_price - dis_deduce;
            
            cout << "-----------------------------------------------------------------------\n";
        	cout << "\tYou choose Max Payne 3!";
            cout << "\n\n\tCombining cutting edge shooting mechanics\n\twith a dark and twisted story, Max Payne 3\n\tis a seamless, highly detailed,\n\tcinematic experience from Rockstar Games.";
            cout << "\n\n\tThis complete edition of Max Payne 3 includes:-\n\t [] The complete original game\n\t [] Deathmatch Made In Heaven DLC\n\t [] Painful Memories Pack DLC\n\t [] Silent Killer Loadout Pack DLC\n\n";
            cout << "-----------------------------------------------------------------------\n";
            cout << "\tThe game's original price is RM" << actualgame_price << "\n\tand the game is on discount around " << discount << "%!";
            cout << "\n-----------------------------------------------------------------------\n";
            cout << "\n\nThe game's price after discount is now RM" << totalafter_dis << "!\n";
            
            cout << "\nConfirm purchase? (Y/N): ";
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (confirm == 'Y'||confirm == 'y'){
            	cout << "\nPlease insert the amount of money you paid: ";
            	cin >> input_money;
            	if (input_money > totalafter_dis) {
            		system ("cls");
            		bal = input_money - totalafter_dis;
            		cout << "Success! You now have RM" << bal << " left!";
			    } else {
					system ("cls");
					bal = totalafter_dis - input_money;
					cout << "Error! Not enough money to pay for the game! You need RM" << bal << " more!";
			    }	
			} else {
				system ("cls");
				cout << "You have cancelled your purchase, returning to main menu..\n";
				system ("PAUSE");
                goto start;
			}
			
            break;
        
		// Option 3  
        case '3':
        	system ("cls");
        	system ("Color 80");
        	actualgame_price = 69.0;
        	discount = 75.0;
            dis_deduce = actualgame_price * (discount/100);
            totalafter_dis = actualgame_price - dis_deduce;
        	
        	cout << "-----------------------------------------------------------------------\n";
        	cout << "\tYou choose The Escapists 2!";
            cout << "\n\n\tRisk it all to breakout\n\tfrom the toughest prisons in the world.\n\tExplore the biggest prisons yet,\n\twith multiple floors, roofs, vents and underground tunnels.";
            cout << "\n\n\tThe games includes multiple features! such as:-\n\t [] 11 Prisons\n\t [] Up to 4 player co-operative and versus multiplayer\n\t [] Over 300 customisations\n\t [] Prison Map Editor\n\n";
            cout << "-----------------------------------------------------------------------\n";
            cout << "\tThe game's original price is RM" << actualgame_price << "\n\tand the game is on discount around " << discount << "%!";
            cout << "\n-----------------------------------------------------------------------\n";
            cout << "\n\nThe game's price after discount is now RM" << totalafter_dis << "!\n";
            
            cout << "\nConfirm purchase? (Y/N): ";
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (confirm == 'Y'||confirm == 'y'){
            	cout << "\nPlease insert the amount of money you paid: ";
            	cin >> input_money;
            	if (input_money > totalafter_dis) {
            	system ("cls");
            	bal = input_money - totalafter_dis;
            	cout << "Success! You now have RM" << bal << " left!";
			    } else {
				system ("cls");
					bal = totalafter_dis - input_money;
					cout << "Error! Not enough money to pay for the game! You need RM" << bal << " more!";
			    }	
			} else {
				system ("cls");
				cout << "You have cancelled your purchase, returning to main menu..\n";
				system ("PAUSE");
                goto start;
			}
			
            break;
        
		// selector doesnt match any valid numbers   
        default:
        	system ("cls");
            cout << "\nError! Choosen option is either not available or does not exist!\n\n";
            system ("PAUSE");
            goto start;
            break;
    }

	cout << "\n\n--------------END OF PROGRAM, THANKS FOR BROWSING!--------------\n\n";
	system ("PAUSE");
	return 0;
	
}

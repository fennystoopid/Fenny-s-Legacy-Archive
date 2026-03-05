#include <iostream>
#include<cstdlib>
#include <fstream> 
#include <windows.h>
using namespace std;

void logo()
{
	cout<<"\t\t                              .. .:--=++**++==-:.                                          "<<endl
     	<<"\t\t                          .-###%%%%#+:::::-=+#%##*-...                                  "<<endl
    	<<"\t\t                     ..=#%%%%%%%%#:.            ....+#%#+..                              "<<endl
	    <<"\t\t                     :*%%%%%%%%%%%=...                 ...=%%#:                             "<<endl
	    <<"\t\t               ...+##*-:-+#%%%%%+..                         -#%+...                "<<endl
	    <<"\t\t            .:%+:.      .#%%.                             .+%*:.                 "<<endl
	    <<"\t\t            ..#+..         .%%                                .=#*..                     "<<endl
	    <<"\t\t         ...+#*              :%*                                  .+%+..                  "<<endl
	    <<"\t\t         .-##:.              :%*                                    .##-.                "<<endl
	    <<"\t\t       ..=#+..               :%*                                     .=#=..                "<<endl
	    <<"\t\t      ,.#-                  .%%#-                                       -#.               "<<endl
	    <<"\t\t      .+#-.                ..*%%%#-.          ...-=+++=:.                .-#+.             "<<endl
	    <<"\t\t      =%-                 .:#%%%%%#-.         :*%%%%%%%%#+:.               -%=              "<<endl
	    <<"\t\t     :#*                 .=#%%%%%%%%*.     ..+%%%%%%%%%%%%#-.              .+%:        "<<endl
	    <<"\t\t    .#.                .-%%%%%%%%%%%#     .#%%%%%%%%%%%%%%%+..             .#.     "<<endl
	    <<"\t\t    -#=                 .=%%%%%%%%%%%%   ..*%%%%%%%%%%%%%%%%%+               -#-      "<<endl
	    <<"\t\t  ..+#.                 .-%%%%%%%%%%%%    +%%%%%%%%%%%%%%%%%%%:              .#+.     "<<endl
	    <<"\t\t   :*.                 .-%%%%%%%%%%%   :%%%%%%%%%%%%%%%%%%%#.             .*:   "<<endl
	    <<"\t\t   :#=.                 .-%%#%%#%%##%=   -%%%%%%%%%%%%%%%%%%%%#.             .-#-          "<<endl
	    <<"\t\t   -#-.                  -#%-#%:*#=+%-  .-%%%%%%%%%%%%%%%%%%%%#:             .:#-      "<<endl
	    <<"\t\t   -#:.                  :*%-#%.+#-+%:  .-%%%%%%%%%%%%%%%%%%%%#:             .:#=   "<<endl
	    <<"\t\t   -#-.                  .+%-#%.=*:+%.  .-%%%%%%%%%%%%%%%%%%%%#:             .:#-       "<<endl
	    <<"\t\t   :#=.                  .+#-%.=:+%.   :#%%%%%%%%%%%%%%%%%%%#.             .-#-.   "<<endl
	    <<"\t\t  :*.                  .=:+%.-+.+%.    +%%%%%%%%%%%%%%%%%%%-              .+*:          "<<endl
	    <<"\t\t   .+#.                  .=:=%.-+.+#.    .%%%%%%%%%%%%%%%%%=               .#+.  "<<endl
	    <<"\t\t    -#=                  .=+.-#.-+.+.     .%%%%%%%%%%%%%%%- .              -#-          "<<endl
	    <<"\t\t    .*#.                 .=+.:#.-+ ++.     ..=%%%%%%%%%%%%#:.              ..##.  "<<endl
	    <<"\t\t    .:#+                 .-=...- =-.       ..*%%%%%%%%#=..                +%-          "<<endl
	    <<"\t\t    ..=%-.                :-..+.-* -:.         .-#%%%%%#-.                 -%+            "<<endl
	    <<"\t\t      .#-                ....-.:= :.          ..-#%%%.                 .-#*..        "<<endl
	    <<"\t\t      ..#-.                                     .-#%%.                ..-#.        "<<endl
	    <<"\t\t        .+#-.                                    ..*%=                 .-#+..     "<<endl
	    <<"\t\t         .=#=..                                    +%:               ..=#=..              "<<endl
	    <<"\t\t          .-#:                                    *%:             ...#-.                  "<<endl
	    <<"\t\t           ..+#+                                   *%-           ...+%+...            "<<endl
	    <<"\t\t             .:#=.                              ..+%%.         ..=#:..                    "<<endl
	    <<"\t\t               .:#+.                            ..%%.      ..+#:...                 "<<endl
	    <<"\t\t                ..:+##-                           =%%%%%#+-:-+##+:...                      "<<endl
	    <<"\t\t                  ....:*%#=.                    ..-%%%%%%%%%%%#:..                        "<<endl
	    <<"\t\t                       ...+#%#+.                :#%%%%%%%%%+..                           "<<endl
	    <<"\t\t                          ...-%%%#+--:...:=#%%%%%%%#-.....                          "<<endl
	    <<"\t\t                                   .:-==+**+==-:.                                          "<<endl;
}
	    
int main()
{
	char opt_menu,menu_t,sentinel,choice;
	string item[1000];
	float sum, price,price_t = 0, total_price[1000];
	int num=1, x, y, numy =1,total_q ,sum_q = 0, quantity[1000];


for(int y = 0; y<numy; y++)	{
		logo();
		cout<<"\n\n\t\t\t\t\t      Welcome To KMKN Restaurant"<<endl<<endl;


   
for(int x = 0; x<num ; x++ ){
   cout	    <<"\t\t\t\t                   Menu Options"<<endl
	    <<"\t\t\t\t------------------------------------------------------"<<endl
	    <<"\t\t\t\t: [1] Traditional Foods                              :"<<endl
	    <<"\t\t\t\t: [2] Western Foods                                  :"<<endl
	    <<"\t\t\t\t: [3] Others                                         :"<<endl
	    <<"\t\t\t\t: [4] Beverages                                      :"<<endl
	    <<"\t\t\t\t------------------------------------------------------"<<endl
	     <<"\n\t\t\t\tPick Options [] To Take Your Order :";
	    
   cin>>opt_menu;
    Beep(613,340);
    
   switch(opt_menu)
   {
   	// Traditinal Menu 
   	case'1':
   		system("cls");
   		cout<<"\t\t\t\t               Traditional Menu"<<endl
   		<<"\t\t\t\t------------------------------------------------------"<<endl
   		<<"\t\t\t\t:       Items                           Price        :"<<endl
   		<<"\t\t\t\t: [1] Nasi Ayam                         RM 7.00      :"<<endl
   		<<"\t\t\t\t: [2] Nasi Lemak                        RM 6.50      :"<<endl
   		<<"\t\t\t\t: [3] Roti Canai                        RM 3.30      :"<<endl
   		<<"\t\t\t\t: [4] Nasi Goreng Kampung               RM 8.00      :"<<endl
   		<<"\t\t\t\t: [5] Nasi Goreng Pattaya               RM 8.60      :"<<endl
   		<<"\t\t\t\t------------------------------------------------------"<<endl;
   	   
	    cout<<"\n\t\t\t\tPick Options [] To Take Your Order :";
        cin>>menu_t;
        Beep(613,340);
        if(menu_t=='1'){		    
	       	price= 7;
			 item[x]="Nasi Ayam          ";
        }
        else if (menu_t=='2'){		    
		price=6.5;
	    item[x]="Nasi Lemak         ";
        }
        else if (menu_t=='3'){
        	 price=3.30;
			 item[x]="Roti Canai         ";
        }
        else if (menu_t=='4'){
        		price=8;
			 item[x]="Nasi Goreng Kampung" ;
        }
        else if (menu_t=='5'){
        	price=8.6;
			item[x]="Nasi Goreng Pattaya" ;
        }
        else{
        	cout<<"\n\n\t\t\t\tInvalid Input";
        }
        
        
        
      
        cout<<"\n\t\t\t\t Enter quantity :";
        cin>>quantity[x];
        Beep(613,340);
        total_price[x]= price*quantity[x];

        break;
    // Western Menu
    case'2':
    	system("cls");
   		cout<<"\t\t\t\t                  Western Menu"<<endl
   		<<"\t\t\t\t------------------------------------------------------"<<endl
   		<<"\t\t\t\t:       Items                           Price        :"<<endl
   		<<"\t\t\t\t: [1] Chicken Chop                      RM 10.00     :"<<endl
   		<<"\t\t\t\t: [2] Lamb Chop                         RM 12.50     :"<<endl
   		<<"\t\t\t\t: [3] Fish And Chips                    RM 11.30     :"<<endl
   		<<"\t\t\t\t: [4] Cheeseburger                      RM 9.50      :"<<endl
   		<<"\t\t\t\t: [5] Chicken Wings                     RM 9.90      :"<<endl
   		<<"\t\t\t\t------------------------------------------------------"<<endl;
   	   
	    cout<<"\n\t\t\t\tPick Options [] To Take Your Order :";
        cin>>menu_t;
           Beep(613,340);
       if(menu_t=='1'){		    
	       	price= 10;
			 item[x]="Chicken Chop       ";
        }
        else if (menu_t=='2'){		    
		price=12.5;
	    item[x]="Lamb Chop          ";
        }
        else if (menu_t=='3'){
        	 price=11.30;
			 item[x]="Fish And Chips      ";
        }
        else if (menu_t=='4'){
        		price=9.5;
			 item[x]="Cheeseburger       " ;
        }
        else if (menu_t=='5'){
        	price=9.9;
			item[x]="Chicken Wings     " ;
        }
        else{
        	cout<<"\n\n\t\t\t\tInvalid Input";
        }
        
        cout<<"\n\t\t\t\t Enter quantity :";
        cin>>quantity[x];
           Beep(613,340);
        total_price[x]= price*quantity[x];

        break;
    // Others Menu
    case'3':
    	system("cls");
        		cout<<"\t\t\t\t                    Others "<<endl
   		<<"\t\t\t\t------------------------------------------------------"<<endl
   		<<"\t\t\t\t:       Items                           Price        :"<<endl
   		<<"\t\t\t\t: [1] Vanilla Ice Cream                 RM 3.50      :"<<endl
   		<<"\t\t\t\t: [2] Banana Fritters                   RM 7.50      :"<<endl
   		<<"\t\t\t\t: [3] Chocolate Cake                    RM 11.50     :"<<endl
   		<<"\t\t\t\t: [4] Egg Tart                          RM 2.50      :"<<endl
   		<<"\t\t\t\t: [5] Cream Puff                        RM 3.60      :"<<endl
   		<<"\t\t\t\t------------------------------------------------------"<<endl;
   	   
	    cout<<"\n\t\t\t\tPick Options [] To Take Your Order :";
        cin>>menu_t;
           Beep(613,340);
       if(menu_t=='1'){		    
	       	price= 3.5;
			 item[x]="Vanilla Ice Cream  ";
        }
        else if (menu_t=='2'){		    
		price=7.5;
	    item[x]="Banana Fritters    ";
        }
        else if (menu_t=='3'){
        	 price=11.50;
			 item[x]="Chocolate Cake     ";
        }
        else if (menu_t=='4'){
        		price=2.5;
			 item[x]="Egg Tart           " ;
        }
        else if (menu_t=='5'){
        	price=3.6;
			item[x]="Cream Puff         " ;
        }
        else{
        	cout<<"\n\n\t\t\t\tInvalid Input";
        }
        
        
        cout<<"\n\t\t\t\t Enter quantity :";
        cin>>quantity[x];
           Beep(613,340);
        total_price[x]= price*quantity[x];

        break;
    //Beverages Menu
    case'4':
    	system("cls");
       		cout<<"\t\t\t\t                   Beverages"<<endl
   		<<"\t\t\t\t------------------------------------------------------"<<endl
   		<<"\t\t\t\t:       Items                           Price        :"<<endl
   		<<"\t\t\t\t: [1] Mineral Water                     RM 1.00      :"<<endl
   		<<"\t\t\t\t: [2] Iced Milo                         RM 3.50      :"<<endl
   		<<"\t\t\t\t: [3] Iced Lemon Tea                    RM 3.30      :"<<endl
   		<<"\t\t\t\t: [4] Coffee                            RM 3.00      :"<<endl
   		<<"\t\t\t\t: [5] Milkshake                         RM 7.50      :"<<endl
   		<<"\t\t\t\t------------------------------------------------------"<<endl;
   	   
	    cout<<"\n\t\t\t\tPick Options [] To Take Your Order :";
        cin>>menu_t;
           Beep(613,340);
       if(menu_t=='1'){		    
	       	price= 1;
			 item[x]="Mineral Water      ";
        }
        else if (menu_t=='2'){		    
		price=3.5;
	    item[x]="Iced Milo          ";
        }
        else if (menu_t=='3'){
        	 price=3.30;
			 item[x]="Iced Lemon Tea     ";
        }
        else if (menu_t=='4'){
        		price=3;
			 item[x]="Coffee             " ;
        }
        else if (menu_t=='5'){
        	price=7.5;
			item[x]="Milkshake          " ;
        }
        else{
        	cout<<"\n\n\t\t\t\tInvalid Input";
        }
        
        
        cout<<"\n\t\t\t\t Enter quantity :";
        cin>>quantity[x];
           Beep(613,340);
        total_price[x]= price*quantity[x];
 
  	
	    break;
    default:
    	cout<<"\n\t\t\t\t Invalid Input!!"<<endl<<endl;
    	break;
   }
        sum= price_t+ total_price[x];
        price_t=sum;
        total_q=sum_q+quantity[x];
        sum_q=total_q;

   cout<<"\n\n\t\t\t\tIs that all? Press 'y' to order more or Press'n' to stop ordering : ";
   cin>>sentinel;
      Beep(613,340);
   if(sentinel == 'y')
   { num=num+1;}
   system("cls");
   
} 
	 
	 
	   //Print out the receipt
	   system("cls");
        ofstream Save("ReceiptRestaurant.doc");
		int print ;
	   cout<<"\n\n\t\t\t\t\t\t\t Receipt"<<endl
	       <<"\t\t\t-------------------------------------------------------------------------------"<<endl
	       <<"\t\t\t  Items                                                    Quantity    Price    "<<endl;
	       
   	   for(int x=0; x<num;x++) 
	{
		cout<<"\t\t\t "<<item[x]<<"                                          "<<quantity[x]<<"        RM "<<total_price[x]<<endl;
   
    }
		cout<<"\t\t\t Total :                                                      "<<total_q<<"        RM "<<sum<<endl
		<<"\t\t\t------------------------------------------------------------------------------"<<endl;
   
         cout<<"\n\n\t\tDo you to print the receipt ? Press 1 to print the receipt ";
   cin>>print;
      Beep(613,340);
   if(print == 1)
   {
           Save<<"\n\n\t\t\t\t\t\t KMKN Restaurant";
           Save<<"\t\t\t\t\t\t Receipt"<<endl;
	       Save<<"\t\t-------------------------------------------------------------"<<endl;
	       Save<<"\t\t  Items                                  Quantity    Price    "<<endl;
	       
   	   for(int x=0; x<num;x++) 
	{
		Save<<"\t\t "<<item[x]<<"                        "<<quantity[x]<<"        RM "<<total_price[x]<<endl;
   
    }
		Save<<"\t\t Total :                                    "<<total_q<<"        RM "<<sum<<endl;
		Save<<"\t\t------------------------------------------------------------"<<endl;
		
			cout<<endl<<endl<<"\t\t\t" <<"File is being saved by the name of ReceiptRestaurant.doc"<<endl<<endl<<endl;
			Save.close();
    }
   
      cout<<"\n\n\t\tDo you to make another order? Press 'y' to make another order or Press'n' to stop the programme : ";
   cin>>choice;
      Beep(613,340);
   if(choice == 'y')
   { numy=numy+1;}
   system("cls");
}
return 0;
}

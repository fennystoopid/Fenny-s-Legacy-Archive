#include <iostream>
#include <fstream>
#include <cmath>
#include <ios> 
#include <limits> 
#include <stdlib.h>
#include <ctime>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string MenuName[200];
int NoOfSet[200],FSet,LSet,VSet,FSpecial,KSet,col=12;
float FoodPrice[200],TotFoodPrice[200],TotPrice[200],DiscPrice[200],TOTAL,TOT_F,TOT_L,TOT_V,TOT_FS,TOT_K,TOTSALES;
ofstream myfile;
char MemberStatus;

//buat funtion utk calculation
float CalcTotSet(float, int);

void Logo(){
	FlushConsoleInputBuffer(hConsole);
	int k = 11;
    	SetConsoleTextAttribute(hConsole, k);
    	cout << "\t\t\t%@@@@@@@@@@@@@@@@@@@@@@@@#+=::.::-=*%@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@@@@@@@@@@*-.:+#%@@@@@@@@@%#*-..-#@@@@@@@@@@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@@@@@@%-.=%@@%*+@.=:*@-==--@@@@@@+:.+@@@@@@@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@@@@=.+@@@@%%@.@@:#@=*-#@@@@@@-.%@@@#:.#@@@@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@@-:%@#+%@@@@:@##+--*@=-==@#:-+=*@@**@@=.+@@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@-.@@=#=*#::-@%@#-:.......@@@@@@#=@-=@*+@@-.#@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@%.#@+**@+=@@@@@%+-:.......:*-:=%@@@*%@=-*@@@%:-@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@*:@@%::@@##@@@--@@@*.......:::#@@=:#@@@=%@@#%@@-.%@@@@=" << endl;
		cout << "\t\t\t%@@@@+:@@@@@@-#@@%:#@@@:..:::.....:-:*@@@%:*@@@@@@@*%@+.#@@@=" << endl;
		cout << "\t\t\t%@@@*:@@@@@@@-....:%@@*.:=+==--==+=....+@@*:..:*##@-*#@+.%@@=" << endl;
		cout << "\t\t\t%@@%.@@@:@@@:-:...-++...................*:+-:-==.%*:%@@@-:@@=" << endl;
		cout << "\t\t\t%@@-+@#-=--%=.=...-=....................+=.....+.#@@@@@@%.+@=" << endl;
		cout << "\t\t\t%@#.@@*..#@@@#::***.--:.................+=*..=-.*@@@@@@@@=.@=" << endl;
		cout << "\t\t\t%@==@*#@@=@@#=@@@@+##+===....++**%@.......+#*#@#-@@@@@@@@#.#=" << endl;
		cout << "\t\t\t%@:*@==+#-@@-#@@@@+..#@@@=...-@@@@*........:@@@@.@%::-*+@@.==" << endl;
		cout << "\t\t\t%@:#@@#=#@@@:%@@@*...@@.+@:..#=:+=@-........:@@@.@@@@-%=@@.-=" << endl;
		cout << "\t\t\t%@:#@+#@@:@@-%@@%....-@@@@@@@%%%%@+..........-@@.@@@@@%@@@.==" << endl;
		cout << "\t\t\t%@-*@+%@%=@@++@@#:+:..+@@@@@@#......=-.......#@%:@@%%%%%@%.+=" << endl;
		cout << "\t\t\t%@+-@%#@@@+@@:@@@-:-.....-......:.:...-...=%@@@-%@@=:%@=@*.%=" << endl;
		cout << "\t\t\t%@%.%@-@@@=%@*=@@+.......+.......-...*@@:*@@@@*=@@+%@=-*@::@=" << endl;
		cout << "\t\t\t%@@=-@%-::=#@@+=@@@#-....-:......:==@@+..#@@@*-@@#:@@@%@*.#@=" << endl;
		cout << "\t\t\t%@@@:*@@@@%:@@@#:@@=..=.+::%+.=:.*-:....*@@@=+@@#*@-@-%%.=@@=" << endl;
		cout << "\t\t\t%@@@%.#@@-@-#:%@@==%..................:%@@*-@@@*%@@=:%@:-@@@=" << endl;
		cout << "\t\t\t%@@@@%.#@%::%@@@@@@==+:...:........:#@@@=-%@@@@=:@@@@@::@@@@=" << endl;
		cout << "\t\t\t%@@@@@%.+@@+#%#@-#@@@%=:=#%%%%%@@@@%+:-%@@@@#::+:@@@#.-@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@-:@@@-=-@@@@@@@@@@%*+====*#@@@@@@@@@@@@@@@@-.#@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@.:@@@@#%@@@@@@@@@@@@@@@@@@@@@@@@@@#%@@@+.-@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@@%::%@@##+@@@@@-#+--%#:===.*@@@@=##@@=.-@@@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@@@@@-.=%@@%:=@@+*-*-*:#-%=%@@=:%@@+..*@@@@@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@@@@@@@%=.:=%@@@*#@+#@+:-@:@@@@*:.:*@@@@@@@@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@@@@@@@@@@@@+:...-=+***+=-....-*@@@@@@@@@@@@@@@@@@@=" << endl;
		cout << "\t\t\t%@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;	
	SetConsoleTextAttribute(hConsole, 15);
}

void Time(){
	 // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "\n\t\t\t\t\t" << dt ;
}

void Time_file(){
	 // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   myfile << "\n\t\t\t\t\t\t\t" << dt ;
}

void Heading(){
	cout<<"\t\t\t| CODE |"<<" SET NAME   |"<<" SET DESCRIPTION             |"<<" PRICE   |"<<endl;
}

// Meal sets available to purchase
void FamilySet(){
	cout<<"\t\t\t|  1.  |"<<" FAMILY SET |"<<" Large Pepperoni Pizza x 2   |"<<" RM80.00 |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" Large Hawaiian Pizza x 2    |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" BBQ Chicken (6 pieces) x 2  |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" Coca-Cola (L) x 6           |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" For 6-8 People              |"<<"         |"<<endl;
}

void LunchSet(){
	cout<<"\t\t\t|  2.  |"<<" LUNCH SET  |"<<" Medium Pepperoni Pizza x 1  |"<<" RM38.00 |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" Medium Hawaiian Pizza x 1   |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" BBQ Chicken (6 pieces) x 1  |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" Coca-Cola (M) x 2           |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" For 2-4 People              |"<<"         |"<<endl;
}
void ValueSet(){
	cout<<"\t\t\t|  3.  |"<<" VALUE SET  |"<<" Small Pepperoni Pizza x 1   |"<<" RM15.00 |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" Small Hawaiian Pizza x 1    |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" Coca-Cola (M) x 2           |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" For 2-4 People              |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<"                             |"<<"         |"<<endl;
}

void Freddy(){
	cout<<"\t\t\t|  4.  |"<<" FREDDY'S   |"<<" Large Pepperoni Pizza x 3   |"<<" RM95.00 |"<<endl;
	cout<<"\t\t\t|      |"<<" SPECIAL    |"<<" Large Cheese Pizza x 3      |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" BBQ Chicken (6 Pieces) x 3  |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" Coca-Cola (M) x 8           |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" For 8-10 People             |"<<"         |"<<endl;
}

void KidSet(){
	cout<<"\t\t\t|  5.  |"<<" KID'S SET  |"<<" Small Cheese Pizza x 1      |"<<" RM18.00 |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" Dino Nuggets (6 Pieces) x 1 |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" Iced Milo (M) x 1           |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<" For 1 Person Only           |"<<"         |"<<endl;
	cout<<"\t\t\t|      |"<<"            |"<<"                             |"<<"         |"<<endl;
}


//print line?
void printline(){
	cout<<"\t\t\t-------------------------------------------------------------"<<endl;
}

void printline_file(){
	 myfile<<"\t\t\t-----------------------------------------------------------------------------------------------------"<<endl;
}
//address
void address(){
	int k = 9;
    SetConsoleTextAttribute(hConsole, k);
	cout << "\n\t\t\t\t\tFreddy Fazbear Pizzeria,\n\t\t\t\t\tLot 566 Kedah Darul Aman, \n\t\t\t\t\t06300 Kuala Nerang, Kedah." <<endl;
	cout << "\n\t\t\t\t\tContact Number : 011-1299-7499"<<endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void address_file(){
	myfile << "\n\t\t\t\t\t\t\tFreddy Fazbear Pizzeria,\n\t\t\t\t\t\t\tLot 566 Kedah Darul Aman, \n\t\t\t\t\t\t\t06300 Kuala Nerang, Kedah." <<endl;
	myfile << "\n\t\t\t\t\t\t\tContact Number : 011-1299-7499"<<endl;
}





//main, starting point
int main() {
    char Continue,AddOrder,Menu;
    int  counter,c1=0,c2=-1, CustomerNum = 1;
    float Disc,Money,Balance;
    string CustomerName,CustomerNo,CustomerAdd,StaffName, StaffID;
    counter = 0;
    printline();
    cout<<"\t\t\t\t      Staff Name : ";
    cin>>StaffName;
    cout<<"\t\t\t\t      Staff ID : ";
    cin>>StaffID;
    system ("cls");
    printline();
    cout << "\n\t\t\t\t\t\tWelcome, " << StaffName << endl << "\n";
    printline();
    
  do{// Loop A : Customer
   	c2=0;
   	Logo();
	address();
    cout<<endl;
    Time();
	   
    printline();
    cout<<"\n\t\t\t\t      Welcome To Freddy Fazbear Pizzeria!\n"<<endl;
    printline();
    
    cout<<"\n\t\t\t\t      Customer's Details"<<endl;
    cout<<"\t\t\t\t      Name             : ";
    cin>>CustomerName;
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  	cin.clear();
  	cin.sync();
    cout<<"\t\t\t\t      Contact No.      : ";
    cin>>CustomerNo;
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  	cin.clear();
  	cin.sync();
    cout<<"\t\t\t\t      Address          : ";
    cin>>CustomerAdd;
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  	cin.clear();
  	cin.sync();
    cout<<"\t\t\t\t      Membership (Y/N) : ";
    cin>>MemberStatus;
    // Clear input buffer
    cin.ignore(2,'\n');
  	cin.clear();
  	cin.sync();
    
    if (MemberStatus == 'Y' || MemberStatus == 'y') {
    	Disc = 0.15;
    }
    TOTAL = 0;
    
    counter = 0;
    do{ //Loop B : Add Order
    c1++;
    c2++;
    
    //Start of the main menu full of food set yummy
    system ("cls");
    MENU:
    printline();
    Heading();
    printline();
    FamilySet();
    printline();
    LunchSet();
    printline();
    ValueSet();
    printline();
    Freddy();
    printline();
    KidSet();
    printline();
    cout<<"\t\t\t\t      CHOOSE A MENU :";
    cin>>Menu;
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  	cin.clear();
  	cin.sync();
  	
  	
    switch(Menu){
        case'1':
        	system ("cls");
            printline();
            FamilySet();
            printline();
            FoodPrice[c2] = 80;
            cout<<"\t\t\t\t      AMOUNT OF SET :";
            cin>>NoOfSet[c2];
            // Clear input buffer
    		cin.ignore(numeric_limits<streamsize>::max(),'\n');
  			cin.clear();
  			cin.sync();
            MenuName[c2]= "[FAMILY SET]";
            FSet = FSet + NoOfSet[c2]; 
        break;
        
        case'2':
        	system ("cls");
            printline();
            LunchSet();
            printline();
            FoodPrice[c2] = 38;
            cout<<"\t\t\t\t      AMOUNT OF SET :";
            cin>>NoOfSet[c2];
            // Clear input buffer
    		cin.ignore(numeric_limits<streamsize>::max(),'\n');
  			cin.clear();
  			cin.sync();
            MenuName[c2]= "[LUNCH SET]";
            LSet = LSet + NoOfSet[c2]; 
        break;
        
        case'3':
        	system ("cls");
            printline();
            ValueSet();
            printline();
            FoodPrice[c2] = 15;
            cout<<"\t\t\t\t      AMOUNT OF SET :";
            cin>>NoOfSet[c2];
            // Clear input buffer
    		cin.ignore(numeric_limits<streamsize>::max(),'\n');
  			cin.clear();
  			cin.sync();
            MenuName[c2]= "[VALUE SET]";
            VSet = VSet + NoOfSet[c2]; 
        break;
        
         
        case'4':
        	system ("cls");
            printline();
            Freddy();
            printline();
            FoodPrice[c2] = 95;
            cout<<"\t\t\t\t      AMOUNT OF SET :";
            cin>>NoOfSet[c2];
            // Clear input buffer
    		cin.ignore(numeric_limits<streamsize>::max(),'\n');
  			cin.clear();
  			cin.sync();
            MenuName[c2]= "[FREDDY'S]";
            FSpecial = FSpecial + NoOfSet[c2]; 
        break;
        
         
        case'5':
        	system ("cls");
            printline();
            KidSet();
            printline();
            FoodPrice[c2] = 18;
            cout<<"\t\t\t\t      AMOUNT OF SET :";
            cin>>NoOfSet[c2];
            // Clear input buffer
    		cin.ignore(numeric_limits<streamsize>::max(),'\n');
  			cin.clear();
  			cin.sync();
            MenuName[c2]= "[KID'S SET]";
            KSet = KSet + NoOfSet[c2]; 
        break;
        
        default :
        	system ("cls");
            printline();
            FlushConsoleInputBuffer(hConsole);
			SetConsoleTextAttribute(hConsole, col);
            cout<<"\t\t\t\t      ERROR! INVALID INPUT! TRY AGAIN"<<endl;
            SetConsoleTextAttribute(hConsole, 15);
            goto MENU;
        break;
    }

    TotFoodPrice[c2] = NoOfSet[c2] * FoodPrice[c2];
    if (MemberStatus == 'Y' || MemberStatus == 'y')  {
    	DiscPrice[c2] = TotFoodPrice[c2] * Disc;
    } else {
    	DiscPrice[c2]= 0;
    }
    
    TotPrice[c2] = TotFoodPrice[c2] - DiscPrice[c2];
    TOTAL = TOTAL + TotPrice[c2];
    
    printline();
    cout<<"\t\t\t\t      Continue Order? (Y/N) : ";
    cin>>AddOrder;
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  	cin.clear();
  	cin.sync();
    /*
    if (AddOrder == 'Y' || AddOrder == 'y'){
       	counter = 0;
       	c1++;
       	c2++;
    } else {
   		counter = 2;
    }
    */
    } while (AddOrder == 'Y' || AddOrder == 'y'); // Close Loop B : Add Order
    
    system ("cls");
    printline();
    address();
    cout<<endl;
    Time();
    printline();
    cout<<"\t\t\t\t\tCustomer's Details"<<endl;
    cout<<"\t\t\t\t\tName              : ";
    cout<<CustomerName<<endl;
    cout<<"\t\t\t\t\tContact No.       : ";
    cout<<CustomerNo<<endl;
    cout<<"\t\t\t\t\tAddress           : ";
    cout<<CustomerAdd<<endl;
    cout<<"\t\t\t\t\tMembership Status : ";
    if (MemberStatus == 'Y' || MemberStatus == 'y')  {
    	cout<<"Member"<<endl;
    } else {
    	cout<<"Non-Member"<<endl;
    }
    printline();
    cout <<"\tNo.";
    cout <<"\tSET NAME";
    cout <<"\tSET PRICE";
    cout <<"\tTOTAL SET";
    cout <<"\tTOTAL PRICE";
    cout <<"\tDISC PRICE";
    cout <<"\tFINAL PRICE"<<endl;
    
    c2 = 0;
    do { // Loop C : Receipt
    	cout<<"\t"<<(c2+1);
    	cout<<"\t"<<MenuName[c2];
    	cout<<"\t"<<FoodPrice[c2];
    	cout<<"\t\t"<<NoOfSet[c2];
    	cout<<"\t\t"<<TotFoodPrice[c2];
    	cout<<"\t\t"<<DiscPrice[c2];
    	cout<<"\t\t"<<TotPrice[c2]<<endl;
    	c2++;
    }   while (c2 < c1); // Close Loop C : Receipt
    
    printline();
    
    //printing receipt into a text file or .txt
    myfile.open ("LIST OF RECEIPT.txt",ios::out | ios::app);
    myfile<<"\t\t\t\t\t\t\tRECEIPT FOR CUSTOMER NO."<<CustomerNum<<endl;
    printline_file();
	address_file();
    myfile<<endl;
    Time_file();
    printline_file();
    myfile<<"\t\t\t\t\t\t\tCustomer's Details"<<endl;
    myfile<<"\t\t\t\t\t\t\tName              : ";
    myfile<<CustomerName<<endl;
    myfile<<"\t\t\t\t\t\t\tContact No.       : ";
    myfile<<CustomerNo<<endl;
    myfile<<"\t\t\t\t\t\t\tAddress           : ";
    myfile<<CustomerAdd<<endl;
    myfile<<"\t\t\t\t\t\t\tMembership Status : ";
    if (MemberStatus == 'Y' || MemberStatus == 'y')  {
        myfile<<"Member"<<endl;
    } else {
    	myfile<<"Non-Member"<<endl;
    }
    printline_file();
    myfile  <<"\t\t\tNo."<<"\tSET NAME"<<"\tSET PRICE"<<"\tTOTAL SET"<<"\tTOTAL PRICE"<<"\tDISC PRICE"<<"\tFINAL PRICE"<<endl;
  
         
    //Loop C@: OUTPUT TO .TXT FILE
    c2=0;
        do{ //output data from array into a table   
            
            myfile<<"\t\t\t"<<(c2+1);
    		myfile<<"\t"<<MenuName[c2];
    		myfile<<"\t"<<FoodPrice[c2];
    		myfile<<"\t\t"<<NoOfSet[c2];
    		myfile<<"\t\t"<<TotFoodPrice[c2];
    		myfile<<"\t\t"<<DiscPrice[c2];
    		myfile<<"\t\t"<<TotPrice[c2]<<endl;
    		c2++;
    	}while (c2 < c1); //close Loop C@ .TXT
    
    printline_file();
    myfile   <<"\t\t\t\t\t\t      TOTAL : RM " << TOTAL<<endl;
    printline_file();
    myfile<<"\n\t\t\t\t\t    THANK YOU FOR VISITING FREDDY FAZBEAR PIZZERIA HUR HUR HUR\n"<<endl;
    myfile<<"\n\n\n";
    myfile.close();
    //end of printing receipt into a text file or .txt

    cout<<"\t\t\t\t        TOTAL : RM"<<TOTAL<<endl;
    cout<<"\t\t\t\t        ENTER AMOUNT OF CASH (RM) :";
    cin>>Money;
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  	cin.clear();
  	cin.sync();
    
    if (Money >= TOTAL) {
    	Balance = Money - TOTAL;
        printline();
       	cout<<"\t\t\t\t        BALANCE : RM"<< Balance << endl;   
    } else{
        printline();
    	cout<<"\t\t\t\t      Insufficient Amount Of Cash, Purchase Cancelled."<<endl;
    	printline();
    }   
    printline();
    cout<<"\t\t\t\t      Next Customer? (Y/N) : ";
    cin>>Continue;
    
    if (Continue == 'Y' || Continue == 'y'){
       	counter = 0;
       	c1 = 0;
       	system ("cls");
       	CustomerNum++;
   } else {
   		counter = 2;
      	system ("cls");
   }
   
} while (counter<1); // Close Loop A : Customer
  
  	printline();
    cout<<"\t\t         THANK YOU FOR WORKING WITH THE FREDDY FAZBEAR HUR HUR HUR"<<endl;
  	printline();
  	address();
  	Time();
  	printline();
  	cout<<"\t\t\t\t        Staff Name : "<<StaffName<<endl;
	cout<<"\t\t\t\t        Staff ID : "<<StaffID<<endl;
  	printline();
  	cout<<"\t\t\t\t        TOTAL CUSTOMER : "<<CustomerNum<<endl;
 
    TOT_F = TOT_F + CalcTotSet(80,FSet);
    TOT_L = TOT_L + CalcTotSet(38,LSet);
    TOT_V = TOT_V + CalcTotSet(15,VSet);
    TOT_FS = TOT_FS + CalcTotSet(95,FSpecial);
    TOT_K = TOT_K + CalcTotSet(18,KSet);

   	printline();  
    cout <<"\t\t\tSET NAME";
	cout <<"\tSET PRICE(RM)";
    cout <<"\tTOTAL SET SOLD";
    cout <<"\tTOTAL PRICE(RM)"<<endl;
   
    if (MemberStatus == 'Y' || MemberStatus == 'y') {
    	
    	cout <<"\t\t\t[FAMILY SET]";
    	cout <<"\t68";
    	cout <<"\t\t"<<FSet;
    	cout <<"\t\t"<<TOT_F<<endl;
    	
     	cout <<"\t\t\t[LUNCH SET]";
    	cout <<"\t32.3";
    	cout <<"\t\t"<<LSet;
    	cout <<"\t\t"<<TOT_L<<endl;
    
     	cout <<"\t\t\t[VALUE SET]";
    	cout <<"\t12.75";
    	cout <<"\t\t"<<VSet;
    	cout <<"\t\t"<<TOT_V<<endl;
    
     	cout <<"\t\t\t[FREDDY'S]";
    	cout <<"\t80.75";
    	cout <<"\t\t"<<FSpecial;
    	cout <<"\t\t"<<TOT_FS<<endl;
    
     	cout <<"\t\t\t[FAMILY SET]";
    	cout <<"\t15.3";
    	cout <<"\t\t"<<KSet;
    	cout <<"\t\t"<<TOT_K<<endl;
    
    } else {
    	//TOT = Price * SetNum;
    
     	cout <<"\t\t\t[FAMILY SET]";
    	cout <<"\t80";
    	cout <<"\t\t"<<FSet;
    	cout <<"\t\t"<<TOT_F<<endl;
    
     	cout <<"\t\t\t[LUNCH SET]";
    	cout <<"\t38";
    	cout <<"\t\t"<<LSet;
    	cout <<"\t\t"<<TOT_L<<endl;
    
     	cout <<"\t\t\t[VALUE SET]";
    	cout <<"\t15";
    	cout <<"\t\t"<<VSet;
    	cout <<"\t\t"<<TOT_V<<endl;
    
     	cout <<"\t\t\t[FREDDY'S]";
    	cout <<"\t95";
    	cout <<"\t\t"<<FSpecial;
    	cout <<"\t\t"<<TOT_FS<<endl;
    
     	cout <<"\t\t\t[FAMILY SET]";
    	cout <<"\t18";
    	cout <<"\t\t"<<KSet;
    	cout <<"\t\t"<<TOT_K<<endl;
    }
    
	printline();
    TOTSALES = TOT_F + TOT_L + TOT_V + TOT_FS + TOT_K;
    cout<<"\t\t\t\t        TOTAL SALES : RM"<<TOTSALES<<endl;
    printline;
    
	return 0;
	
}

float CalcTotSet(float Price, int SetNum){
	float TOT, Disc;
	if (MemberStatus == 'Y' || MemberStatus == 'y') {
    	Disc = (Price * SetNum) * 0.15;
		TOT = Price * SetNum - Disc;
    } else {
    	TOT = Price * SetNum;
    }
    return(TOT);
}


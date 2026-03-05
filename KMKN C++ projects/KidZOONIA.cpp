#include <iostream>
#include <string>
using namespace std;
int main() 	{
      string Name, MSstate; 
      char MemberShip;
      int  KidNum;
      float Discount=0, NormalPrice=50.00, TotalPrice;
      float TotalDiscount, TotalAfterDiscount;   
          
      cout << "Enter Name : ";
      getline(cin, Name);
      cout << "Enter Membership (y/n) : ";
      cin >> MemberShip;  //enter : y
      cout << "Enter Number of Children : ";
      cin >> KidNum;
      
	 if (MemberShip == 'y' || MemberShip == 'Y') {
    	       Discount=0.15;
    	       MSstate= "Yes";
     } else if (MemberShip == 'n' || MemberShip == 'N') {	   
	           Discount=0;
               MSstate= "No";
	 } else {
             Discount=0;
             MSstate= "Assumed as No (No data or no matching data provided)";       
     }

      TotalPrice = (KidNum * NormalPrice);
      TotalDiscount = (KidNum * NormalPrice * Discount);
      TotalAfterDiscount = TotalPrice - TotalDiscount;

       //OUTPUTT
      cout << "\n*********KIDZOONIA CLUB********";
      cout << "\nName : " << Name;
      cout << "\nMembership : " << MSstate;
      cout << "\nNumber of Children : " << KidNum;
      cout << "\nTotal Price : RM" << TotalPrice;
      cout << "\nDiscount Received! : RM" << TotalDiscount;
      cout << "\nAmount Need to Pay : RM" << TotalAfterDiscount;
      return 0; }



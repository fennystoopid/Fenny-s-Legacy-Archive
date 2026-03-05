#include <fstream>   //https://cplusplus.com/doc/tutorial/files/
#include <iostream>
#include <string>
using namespace std;
//=====================================================================
//declare global variable
int totstudent=0;
float TOTBMI=0;
char option;

//=====================================================================
//declare array
string nama[200], rumah[200], acara[200];
float berat[200], tinggi[200], bmi[200];
//=====================================================================

void menu(){
    cout<< "\n++++++++++++++++RUMAH SUKAN++++++++++++++++++";
    cout<< "\n\t A - RUMAH MERAH";  
    cout<< "\n\t B - RUMAH BIRU";  
    cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++";
}
//main function 
int main(){  //start main

    // declare local variables
    int counter=0;
    
            
        cout<<"JUM STUDENT:";
        cin>> totstudent;
        
        //Loop A: while loop to input data into array
        counter=0;
        while (counter < totstudent){//Loop A: input data to array
            menu();
            
            INPUTCODE:
            //process to input data into array
            cout << "\nSTUDENT " << counter+1 <<endl; 
            
            cout << "\tRUMAH : ";
            cin  >> option;
            
            switch(option){
            case 'A':
            case 'a':
                    rumah[counter]="Merah";
                    cin.ignore();
                    cout<<"\tNAMA PELAJAR : ";
                    getline(cin, nama[counter]);
                    //cin.ignore();
                    cout <<"\tACARA : ";
                    getline(cin, acara[counter]);
                    //cin.ignore();
                    cout <<"\tBERAT : ";
                    cin>>berat[counter];
                    cout <<"\tTINGGI : ";
                    cin>>tinggi[counter];
                    bmi[counter]= berat[counter]/(tinggi[counter]*tinggi[counter]);
                    cout <<"\tBMI is "<<bmi[counter];
                    break;
            case 'B':
            case 'b':
                    rumah[counter]="Biru";
                    cin.ignore();
                    cout<<"\tNAMA PELAJAR : ";
                    getline(cin, nama[counter]);
                    //cin.ignore();
                    cout <<"\tACARA : ";
                    getline(cin, acara[counter]);
                    //cin.ignore();
                    cout <<"\tBERAT : ";
                    cin>>berat[counter];
                    cout <<"\tTINGGI : ";
                    cin>>tinggi[counter];
                    bmi[counter]= berat[counter]/(tinggi[counter]*tinggi[counter]);
                    cout <<"\tBMI is "<<bmi[counter];
                    break; 
            default:
                    cout<<"KOD SALAH";
                    goto INPUTCODE;
                    break;
            }    
            TOTBMI=TOTBMI+bmi[counter];
            counter++;
        }// close Loop A
         

        cout <<"\n\nBIL"<<"\tRUMAH\tNAMA\tBERAT\tTINGGI\tBMI\tACARA\n";
        //Loop B: do while loop to output data from array to screen 
        counter=0;
        do{ //output data from array into a table   
            
            cout << (counter+1) ;
            cout <<"\t"<<rumah[counter];
            cout << "\t"<< nama[counter];
            cout << "\t"<< berat[counter];
            cout << "\t"<< tinggi[counter];
            cout << "\t"<< bmi[counter];
            cout << "\t"<< acara[counter];
            cout << "\n";
            counter++;
        }while (counter < totstudent); //close Loop B
        cout <<"\n\nTOTAL BMI IS " << TOTBMI;

          ofstream myfile;  //https://cplusplus.com/doc/tutorial/files/
          myfile.open ("LIST OF RECEIPT.txt",ios::out | ios::app);
          myfile  <<"\n\nBIL"<<"\tRUMAH\tNAMA\tBERAT\tTINGGI\tBMI\tACARA\n";
         
         //Loop C: OUTPUT TO FILE
        counter=0;
        do{ //output data from array into a table   
            
            	myfile  << (counter+1) ;
            	myfile  <<"\t"<<rumah[counter];
            	myfile  << "\t"<< nama[counter];
            	myfile  << "\t"<< berat[counter];
            	myfile  << "\t"<< tinggi[counter];
            	myfile  << "\t"<< bmi[counter];
            	myfile << "\t"<< acara[counter];
            	myfile  << "\n";
            	counter++;
        }while (counter < totstudent); //close Loop C
        	myfile   <<"\n\nTOTAL BMI IS " << TOTBMI;
       myfile.close();
return 0;
} // close main


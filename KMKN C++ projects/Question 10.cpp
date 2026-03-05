#include <iostream>

using namespace std;

int main(){
    
    float inputmile, outputkm;
    
    cout << "Please enter value of mile to be converted into km : ";
    cin >> inputmile;
    
    outputkm = inputmile * 1.6;
    
    cout << "\n" << inputmile <<" miles in kilometers is "<< outputkm << "\n";
    cout << "Conversion successful!";
    return 0;
    
}     

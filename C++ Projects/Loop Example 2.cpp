#include <iostream>
using namespace std;
int main() {
    int Counter,Num, Sum=0;
    cout << "Enter a number :";
    cin >> Num;
    
    for (Counter = 1; Counter <= Num; Counter= Counter+1) 
        Sum = Sum + Counter;   
        
    cout << "Sum of Numbers between 1 to " << Num << " is " << Sum;
    return 0;

}


//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  12/5/22
//converts celsius to fahrenheit.

#include <iostream>
using namespace std; 


int main(){
    double celsius;
    cout << "Please enter a celsius value: ";
    cin >> celsius;
    double fahrenheit = (celsius*9/5) +32;
    cout << "Your value in fahrenheit is: " << fahrenheit;
    return 0;
}
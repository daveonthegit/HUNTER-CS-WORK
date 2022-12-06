//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  12/5/22
//print users academic standing

#include <iostream>
using namespace std; 

int main(){
    int credits;
    cout << "Enter number of credit hours taken: ";
    cin >> credits;
    if(credits <28){
        cout<< "\n freshman";
    }else if(credits <61) {
        cout<< "\n sophomore";
    }else if (credits <94){
        cout<< "\n junior";
    }else{
        cout<< "\n senior";
    }
    return 0;
}
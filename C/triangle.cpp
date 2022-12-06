//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  12/5/22
//prints triangle using character inputted.

#include <iostream>
using namespace std; 

int main(){
    int x;
    char y;
    cout << "Enter an int: ";
    cin >> x;
    cout<< "Enter a symbol other than space: ";
    cin >> y;
    for (int i=1; i<x+1;i++){
        for(int j = x-i;j>-1;j--){
            cout <<" ";
        }
        for(int k = 0; k<i; k++){
            cout <<y;
        }
        cout <<"\n";
    }
    return 0;
}
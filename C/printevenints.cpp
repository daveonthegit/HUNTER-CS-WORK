//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  12/5/22
//print all even ints in given bounds.

#include <iostream>
using namespace std; 

int main(){
    int x; int y;
    cout << "Enter start: ";
    cin >> x;
    cout << "\nEnter end: \n";
    cin >> y;
    for (x;x<y+1;x++){
        if(x%2==0){
            cout << x << '\n';
        }
    }
    return 0;
}
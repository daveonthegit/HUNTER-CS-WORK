//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  12/5/22
//convert decimal to signed binary.

#include <iostream>
using namespace std; 

int main(){ 
    cout << "Enter an int in [-128, 127]: ";
    int x;
    cin >> x;
    int bitStorage[8] = {0,0,0,0,0,0,0,0};
    bool neg = false;
    if(x<0) {
        neg = true;
        x*=-1;
        x-=1;
    }
    for(int i =0 ; i<8; i++) {
        bitStorage[7-i] = x%2;
        if(neg&&bitStorage[7-i]==0){
            bitStorage[7-i]=1;
        }else if(neg&&bitStorage[7-i]==1){
            bitStorage[7-i]=0;
        }
        x/=2;
    }
    cout <<"binary string: ";
    for(int i = 0; i<8; i++) {
        cout << bitStorage[i];
    }
    return 0;
}
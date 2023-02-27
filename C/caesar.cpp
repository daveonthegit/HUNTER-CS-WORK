/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 6 B

Caesar shifts a string using a shift index
*/

#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int rshift){
    int shiftval = int(c);
    if(isupper(c)){
        shiftval-=65;
        shiftval+=rshift;
        if(shiftval>25)
            shiftval-=25;
        shiftval+=65;
    }else{
        shiftval-=97;
        shiftval+=rshift;
        if(shiftval>25)
            shiftval-=25;
        shiftval+=97; 
    }

    return char(shiftval);
}

string encryptCaesar(string plaintext, int rshift){
    string shifttext="";
    for (auto c:plaintext){
        if(isalpha(c))
            shifttext+=shiftChar(c,rshift);
        else   
            shifttext+=c;
    }
    return shifttext;
}

int main() {
    string plaintext; int shift;
    cout<<"Enter plaintext: ";
    getline(cin, plaintext);
    cout<<"Enter shift: ";
    cin>>shift;
    cout<<"Ciphertext: "<<encryptCaesar(plaintext,shift);
    return 0;
}
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
    if(isalpha(c)){
        if(isupper(c)){
            c-=65;
            c+=rshift;
            if(c>25)
                c-=26;
            c+=65;
        }else{
            c-=97;
            c+=rshift;
            if(c>25)
                c-=26;
            c+=97; 
        }
    }

    return c;
}

string encryptCaesar(string plaintext, int rshift){
    string shifttext="";
    for (auto c:plaintext){
        shifttext+=shiftChar(c,rshift);
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
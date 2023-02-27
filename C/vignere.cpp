/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 6 C

Vignere shifts a string using a keyword as index.
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

string encryptVignere(string plaintext, string keyword){
    string ciphertext ="";
    for (int i = 0 ; i<plaintext.length();i++){
        if(isalpha(plaintext[i])){
            if(isupper(plaintext[i])){
                ciphertext+=toupper(keyword[i%keyword.length()]);
            }else{
                ciphertext+=keyword[i%keyword.length()];
            }
        }else{
            ciphertext+=plaintext[i];
        }
    }
    for (int i = 0;i<plaintext.length();i++){
        if(isalpha(plaintext[i])){
        int shiftval;
        if(isupper(plaintext[i])){
            shiftval = int(plaintext[i])-65;
        }else{
            shiftval = int(plaintext[i])-97;
        }
        ciphertext[i]=shiftChar(ciphertext[i],shiftval);
        }
    }
    return ciphertext;
}

int main() {
    string plaintext; string keyword;
    cout<<"Enter plaintext: ";
    getline(cin, plaintext);
    cout<<"Enter keyword: ";
    cin>>keyword;
    cout<<"Ciphertext: "<<encryptVignere(plaintext,keyword);
    return 0;
}

/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 6 D

Decrypts encrypted caesar and vignere ciphers.
*/

#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int shift){
    int shiftval = int(c);
    if(isupper(c)){//Check for character case
        shiftval-=65; //get shiftval to 0<x<25
        shiftval+=shift; //shift the val
        if(shiftval>25) //correct for overshift
            shiftval-=25;
        if(shiftval<0){
            shiftval+=25;
        }
        shiftval+=65;//get char
    }else{
        shiftval-=97;
        shiftval+=shift;
        if(shiftval>25)
            shiftval-=25;
        if(shiftval<0)
            shiftval+=25;
        shiftval+=97; 
    }

    return char(shiftval);
}

string encryptCaesar(string plaintext, int rshift){
    string shifttext=""; //caesar shift is plain shift, each letter is shifted by rshift
    for (auto c:plaintext){
        if(isalpha(c))
            shifttext+=shiftChar(c,rshift);
        else   
            shifttext+=c;
    }
    return shifttext;
}

string decryptCaesar(string ciphertext, int shift){
    return encryptCaesar(ciphertext,-1*shift);
}

string encryptVignere(string plaintext, string keyword){
    string ciphertext ="";
    for (int i = 0 ; i<plaintext.length();i++){
        if(isalpha(plaintext[i])){
            if(isupper(plaintext[i])){
                ciphertext+=toupper(keyword[i%keyword.length()]); //Iterater over plaintext length, insert char of
            }else{ //keyword based off remainder for length and val of i.
                ciphertext+=keyword[i%keyword.length()];
            }
        }else{
            ciphertext+=plaintext[i];
        }
    }
    for (int i = 0;i<plaintext.length();i++){ //get shift val of plaintext.
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

string decryptVignere(string ciphertext, string keyword){
    string plaintext =ciphertext;
    for (int i = 0;i<ciphertext.length();i++){
        if(isalpha(ciphertext[i])){
            int shiftval;
            shiftval = -1*(int(keyword[i%keyword.length()])-97);
            plaintext[i]=shiftChar(plaintext[i],shiftval);
        }
    }
    return plaintext;
}

int main() {
    string plaintext; string keyword; int shift;
    cout<<"Enter plaintext: ";
    getline(cin, plaintext);
    cout<<"\n= Caesar =\n";
    cout<<"Enter shift: ";
    cin>> shift;
    string caesartext = encryptCaesar(plaintext,shift);
    cout<<"Ciphertext: "<<caesartext<<endl;
    string decryptedcaesar = decryptCaesar(caesartext,shift);
    if(decryptedcaesar == plaintext){
        cout<<"Decrypted: " <<decryptedcaesar<<endl;
    } else{
        cout<<"failed "<<decryptedcaesar<<endl;
    }
    cout<<"Enter keyword: ";
    cin>>keyword;
    string vigneretext = encryptVignere(plaintext,keyword);
    cout<<"Ciphertext: "<< vigneretext<<endl;
    string decryptedvignere = decryptVignere(vigneretext,keyword);
    if(decryptedvignere == plaintext){
        cout<<"Decrypted: " <<decryptedvignere<<endl;
    } else{
        cout<<"failed: "<<decryptedvignere<<endl;
    }
    return 0;
}

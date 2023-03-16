/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 6 D

Decrypts encrypted caesar and vignere ci`phers.
*/

#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int shift){
    if(isalpha(c)){
        if(isupper(c)){//Check for character case
            c-=65; //get shiftval to 0<x<25
            c+=shift; //shift the val
            if(c>25) //correct for overshift
                c-=26;
            if(c<0){
                c+=26;
            }
            c+=65;//get char
        }else{
            c-=97;
            c+=shift;
            if(c>25)
                c-=26;
            if(c<0)
                c+=26;
            c+=97; 
        }
    }
    return c;
}

string encryptCaesar(string plaintext, int rshift){
    string shifttext=""; //caesar shift is plain shift, each letter is shifted by rshift
    for (auto c:plaintext){
        shifttext+=shiftChar(c,rshift);

    }
    return shifttext;
}

string decryptCaesar(string ciphertext, int shift){
    return encryptCaesar(ciphertext,-1*shift);
}

string encryptVigenere(string plaintext, string keyword){
    string ciphertext ="";
    int keyword_pos =0;
    for (int i = 0 ; i<plaintext.length();i++){
        if(isalpha(plaintext[i])){
            if(isupper(plaintext[i])){
                ciphertext+=toupper(keyword[keyword_pos%keyword.length()]);
            }else{
                ciphertext+=keyword[keyword_pos%keyword.length()];
            }
            keyword_pos++;
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

string decryptVigenere(string ciphertext, string keyword){
    string plaintext =ciphertext;
    int keyword_pos =0;
    for (int i = 0;i<ciphertext.length();i++){
        if(isalpha(ciphertext[i])){
            int shiftval;
            shiftval = -1*(int(keyword[keyword_pos%keyword.length()])-97);
            plaintext[i]=shiftChar(plaintext[i],shiftval);
            keyword_pos++;
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
    string vigeneretext = encryptVigenere(plaintext,keyword);
    cout<<"Ciphertext: "<< vigeneretext<<endl;
    string decryptedvigenere = decryptVigenere(vigeneretext,keyword);
    if(decryptedvigenere == plaintext){
        cout<<"Decrypted: " <<decryptedvigenere<<endl;
    } else{
        cout<<"failed: "<<decryptedvigenere<<endl;
    }
    return 0;
}

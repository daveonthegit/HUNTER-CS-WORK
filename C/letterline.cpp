/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Exercise 4.8

Prints a letter per line from a word
*/

#include <iostream>
using namespace std;

int main() {
    string word; //initializes word
    cout << "Enter a word: ";
    cin>>word; //inputs word
    for (int i =0; i < word.length(); i++) {
        cout<< word.substr(i,1)<<endl; //prints character by looping through index of string chars and using substr.
    }
    return 0;
}
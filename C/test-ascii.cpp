/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 6 A

prints ascii of each char in a string.
*/

#include <iostream>
using namespace std;

int main() {
    string input;
    cout<<"Input: ";
    cin >> input;
    for (auto c: input){
        cout<< c<< " " << int(c)<<endl;
    }
    return 0;
}
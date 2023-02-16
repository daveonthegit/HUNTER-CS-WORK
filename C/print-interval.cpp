/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 2B

Print from user inputted interval
*/

#include <iostream>
using namespace std;

int main() {
    int l; int u;
    cout <<"Please enter L: ";
    cin >> l; //input lower limit
    cout << "Please enter U: ";
    cin >>u; // input upper limit
    for (int i = l; i <u; i++) { // for loop using limits
        cout << i << " ";
    }
    return 0;
}
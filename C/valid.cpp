/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab quiz 1

Validate input to be 0 < n < 100 then print square
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cout <<"Please enter an integer: ";
    cin >> n;
    while (n < 1 || 99 < n) { // checks if n is correct value
        cout << "Please re-enter: ";
        cin >> n;
    }
    cout << "\nNumber squared is " << n*n; // prints n squared. 
    return 0;
}
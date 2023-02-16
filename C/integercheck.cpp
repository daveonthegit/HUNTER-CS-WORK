/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: E 3.1

Checks if an integer is positive negative or zero.
*/
#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Please enter an Integer: ";//Input sets to int x.
    cin >> x;
    if (x >0) { //checks if x is positive.
        cout << x << " is a positive integer." << endl;
    } else if (x <0) { // checks if x is negative
        cout << x << " is a negative integer." << endl;
    } else { //otherwise x is zero
        cout << x << " is zero." << endl;
    }
    return 0;
}
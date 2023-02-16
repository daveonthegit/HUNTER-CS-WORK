/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab1A

prints out if year is leap year or not
*/
#include <iostream>
using namespace std;

int main() {
    int year; // initialize year as int
    cout << "Please input a year";
    cin >> year; // sets year to input
    if (year%4 != 0) { 
        cout<< "Common year";
    } else if (year %100 != 0) {
        cout<< "Leap year";
    } else if(year%400 != 0) {
        cout<< "Common year";
    } else {
        cout<< "Leap year";
    }
    return 0;
}
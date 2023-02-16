/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab1A

prints out month days
*/

#include <iostream>
using namespace std;

int main(){
    int year; int month; bool ly = false; // initializing year and month int and leap year bool
    cout << "Enter year: ";
    cin >> year;
    cout <<"Enter month: ";
    cin >> month;
    if (year%4 == 0 && year %100 != 0) { //if the year is divisible by 4 and not a century then it is a leap year
        ly = true;
    } else if(year%400 == 0) { // if it is divisible by 400 it is a leap year
        ly = true;
    }
    if(month==2){// if february, take into account leap year
        if (ly){
            cout << "29 days";
        }else{
            cout << "28 days";
        }
    }else if (month <8) {// before august even months are 30 days, odd 31
        if (month%2==0) {
            cout << "30 days";
        } else{
            cout << "31 days";
        }
    } else {
        if (month%2==0) {
            cout << "31 days";
        } else{
            cout << "30 days";
        }
    }

}
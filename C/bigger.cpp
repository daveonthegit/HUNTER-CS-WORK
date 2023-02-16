/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab QUiz 2

Takes value of two integers and compares which is bigger, then prints it out.
*/

#include <iostream>
using namespace std;

int main() {
    int x; int y;//initialization.
    cout<< "Enter the first number: ";
    cin >> x;
    cout<<"Enter the second number: ";
    cin >> y;

    if(x>y){ //comparison
        cout<<x;
    } else {
        cout<<y;
    }
}
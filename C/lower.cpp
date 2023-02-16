/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4

Prints out a lower triangle using user input
*/

#include <iostream>
using namespace std;

int main() {
    int size;
    cout <<"Input side length: ";
    cin>>size;
    cout<<"Shape: "<< endl;
    for (int i = 0; i < size; i++) { //height of triangle
        for (int j = 0;j<i+1;j++) {  //width of triangle use height of triangle in order to determine width
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
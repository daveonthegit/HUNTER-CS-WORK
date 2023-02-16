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
        for (int k =0; k <i;k++) { //print white space using height.
            cout<<" ";
        }
        for (int j = 0;j<(size-i);j++) {  //width of triangle use size - height of triangle in order to determine width
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
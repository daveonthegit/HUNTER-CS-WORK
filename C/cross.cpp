/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4

Prints out a cross using user input
*/

#include <iostream>
using namespace std;

int main() {
    int size;
    cout <<"Input size: ";
    cin>>size;
    cout<<"Shape: "<< endl;
    int x = 0;
    for (int i = 0; i < size; i++) { //height of box
        for (int j = 0;j<size;j++) {  //width of box
            if(j==x||j==((size-1)-x)) { //use x to increment to create cross shape.
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        x++;
        cout<<"\n";
    }
    return 0;
}
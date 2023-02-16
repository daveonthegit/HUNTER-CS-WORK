/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4

Prints out a box using user input
*/

#include <iostream>
using namespace std;

int main() {
    int width; int height;
    cout <<"Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin>> height;
    cout<<"Shape: "<< endl;
    for (int i = 0; i < height; i++) { //height of box
        for (int j = 0;j<width;j++) {  //width of box
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
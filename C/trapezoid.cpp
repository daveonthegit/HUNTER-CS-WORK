/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4

Prints out a trapezoid using user input
*/

#include <iostream>
using namespace std;

int main() {
    int width; int height;
    cout <<"Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin>> height;
    if((height-.5)<=(width/2.0)) {
            cout<<"Shape: "<< endl;
            for (int i = 0; i < height; i++) { //height of trapezoid
                for(int k=0;k<i;k++) { //empty space for trapezoid left
                    cout<<" ";
                }
                for (int j = i;j<width-i;j++) {  //asterisks of trapezoid
                    cout<<"*";
                }
                for(int l=width-i;l<width;l++) { //empty space for trapezoid right
                    cout<<" ";
                }
            cout<<"\n";
        }
    } else{
        cout<<"Impossible shape!" << endl;
    }

    return 0;
}
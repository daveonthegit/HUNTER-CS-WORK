/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 4

Prints out a checkerboard using user input
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
    for (int i = 0; i < height; i++) {//checkerboard if i and j are even then print, or if i and j are not even then print *
        for (int j = 0;j<width;j++) { //otherwise just print empty space
            if(i%2==0){
                if(j%2==0){
                    cout<<"*";
                }else {
                    cout<<" ";
                }
            }else {
                if(j%2!=0){
                    cout<<"*";
                }else {
                    cout<<" ";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
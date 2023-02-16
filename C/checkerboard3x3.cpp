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
            if((i%3==0||i%3==1||i%3==2)&& (i%6<=2)){
                if((j%3==0||j%3==1||j%3==2)&& (j%6<=2)){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }else {
                if((j%3==0||j%3==1||j%3==2)&& (j%6<=2)){
                    cout<<" ";
                } else{
                    cout<<"*";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
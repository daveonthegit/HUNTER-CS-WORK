/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 2c

Edit an array
*/

#include <iostream>
using namespace std;

int main(){
    int x; //initialization
    int y;
    int myData[10];
    for (int i = 0; i < 10; i++){ { //for loop sets all values of myData to 1
        myData[i] = 1;
    } 
    }
    do{
        for (int i = 0; i < 10; i++){  // for loop to print array
            cout << myData[i] << " ";
        } 
        cout << "\n"; //inputs
        cout << "Input index: ";
        cin >> x;
        cout << "Input value: ";
        cin >>y;
        if (0 <= x&& x <10) { // sets myData at index x to y if conditions are met
            myData[x] = y;
        }

    } while(0 <= x&& x <10); // if while condition false, exit
    cout << "Index out of range. Exit.";
    return 0;
}
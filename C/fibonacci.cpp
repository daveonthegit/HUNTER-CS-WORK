/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 2d

fibonacci sequence maker
*/

#include <iostream>
using namespace std;

int main(){
    int fib[60]; //initialize array
    fib[0] = 0; //set 0 to 0
    fib[1] = 1; // set 1 to 1
    for (int i = 2; i <60; i++) { // for loop for all values after 1
        fib[i] = fib[i-1] + fib[i-2]; // add last two values to get value
    }
    for (int i = 0; i < 60; i++) {
        cout << fib[i] << endl;
    }
    return 0;
}
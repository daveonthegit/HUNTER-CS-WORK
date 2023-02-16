/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab quiz 1

Print I love C++ based off input
*/
#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout<<"I love C++.";
    }
    return 0;
}
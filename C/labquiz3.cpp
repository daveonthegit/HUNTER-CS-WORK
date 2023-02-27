/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab quiz 3

Create an array and initialize values from 1 to 10
*/

#include <iostream>
using namespace std;

int main() {
    int array[10];
    for (int i =0; i <10;i++){
        array[i]=i+1;
        cout<<array[i]<<endl;
    }
    return 0;
}
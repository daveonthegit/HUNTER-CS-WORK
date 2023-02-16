/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Exercise 3.5

Checks if series of integers are in increasing or decreasing order.
*/
#include <iostream>
using namespace std;

int main() {
    int nums[3];
    cout << "Enter three integers: ";
    cin >> nums[0] >> nums[1] >> nums [2]; //sets nums to integers.
    if (nums[1] > nums[0]) {
        if (nums[2] > nums[1]) {//checks if increasing
            cout << nums[0] << " "<< nums[1] << " "<< nums[2]<< " is in increasing order.";// if increasing print
            return 0;//then exit
        }
    } else if (nums[0] > nums[1]){
        if (nums[1] > nums[2]){
            cout << nums[0] << " "<< nums[1] << " "<< nums[2]<< " is in decreasing order.";//if decreasing print
            return 0; //then exit
        }
    }
    cout << nums[0] << " "<< nums[1] << " "<< nums[2]<< " is in neither order."; //otherwise negative
    return 0;
}
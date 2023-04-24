/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 12

Vectors
*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector(int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        temp.push_back(i);
    }
    return temp;
}

int main() {
    
}
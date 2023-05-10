/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: labquiz 12

quiz
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n){
    vector<int> temp;
    if(n>0){
        for(int i=n;i>=0;i--){
            temp.push_back(i);
        }
    }
    return temp;
}
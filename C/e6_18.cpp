/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: E6.18

Exercise Homework
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int>append(vector<int>a,vector<int>b){
    for(auto x:b){
        a.push_back(x);
    }
    return a;
}
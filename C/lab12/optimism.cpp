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

vector<int> goodVibes(const vector<int> v){
    vector<int> temp;
    for(int i = 0;i<v.size();i++){
        if(v[i]>-1){//checks if negative
            temp.push_back(v[i]);
        }
    }
    return temp;
}
int main() {
    vector<int> v{1,2,-1,3,4,-1,6};
    
    goodVibes(v); // returns [1,2,3,4,6]
}
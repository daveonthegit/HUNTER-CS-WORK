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

void gogeta(vector<int> &goku, vector<int> &vegeta){
    for(int i= 0;i<vegeta.size();i++){
        goku.push_back(vegeta[i]); //combines vector
    }
    vegeta.clear();
}


int main(){

}
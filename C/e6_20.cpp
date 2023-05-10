/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: E6.20

Exercise Homework
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int>merge_sorted(vector<int>a,vector<int>b){
    vector<int>sorted;
    int x=0,y=0;
    if(a.size()==0){
        return b;
    }else if(b.size()==0){
        return a;
    }
    while(x!=a.size()&&y!=b.size()){
        if(b[y]>=a[x]){
            sorted.push_back(a[x]);
            x++;
        }else{
            sorted.push_back(b[y]);
            y++;
        }
    }
    if(x==a.size()){
        while(y!=b.size()){
            sorted.push_back(b[y]);
            y++;
        }
    }else{
        while(x!=a.size()){
            sorted.push_back(a[x]);
            x++;
        }
    }
    return sorted;
}


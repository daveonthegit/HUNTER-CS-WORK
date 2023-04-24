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

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2){
    vector<int> temp;
    int size = v1.size();
    if(size<v2.size()){
        size=v2.size();
    }
    for(int i =0;i<size;i++){
        if(i<v1.size()&&i<v2.size()){
            temp.push_back(v1[i]+v2[i]);
        }else if(i<v1.size()){
            temp.push_back(v1[i]);
        }else{
            temp.push_back(v2[i]);
        }
    }
    return temp;
}


int main(){
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    vector<int> v3 = sumPairWise(v1, v2); // returns [5, 7, 3]
    for(auto i :v3){
        cout<<i<<endl;
    }
}
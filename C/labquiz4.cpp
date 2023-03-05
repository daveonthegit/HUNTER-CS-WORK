/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab quiz 4

Create an array and initialize values from 1 to 10
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream datatext("data.txt");
    string line;
    while(getline(datatext,line)){
        cout<<line<<endl;
    }
    datatext.close();

}
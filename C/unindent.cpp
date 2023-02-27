/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 7

Unindents input from file.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string removeLeadingSpaces(string line){
    string temp;
    bool start = false;
    for(int i = 0; i<line.length();i++){
        if(!isspace(line[i])){
            start=true;
        }
        if(start){
            temp+=line[i];
        }
    }
    return temp;
}

int main() {
    string line;
    while(getline(cin,line)) {
        cout<<removeLeadingSpaces(line)<<endl;
    }
}
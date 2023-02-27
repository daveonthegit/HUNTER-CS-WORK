/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 7

Inputs correct indenting to file
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
int countChar(string line, char c){
    int x = 0;
    for(auto i : line){
        if(i==c){
            x++;
        }
    }
    return x;
}
int main() {
    string line;
    int num_indents =0;
    while(getline(cin,line)) {
        num_indents-=countChar(line,'}');
        for(int i = 0; i<num_indents;i++){
            cout<<"\t";
        }
        cout<<removeLeadingSpaces(line)<<endl;
        num_indents+=countChar(line,'{');
    }
}
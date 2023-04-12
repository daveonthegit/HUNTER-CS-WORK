/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab Quiz 7

Removes e from string
*/

#include <iostream>
using namespace std;

void remove_e(string & sentence){
    string temp = "";
    for (auto c:sentence){
        if(c!='e')
            temp+=c;
    }
    sentence = temp;
}


int main() {
    string s = "elephant";
    remove_e(s);
    cout<<s<<endl;
}
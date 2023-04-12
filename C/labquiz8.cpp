/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab quiz 8

Returns difference of open and closed brackets.
*/

#include <iostream>

using namespace std;

int unbalanced_brackets(string input){
    int x = 0;
    int y = 0;
    for (int i = 0; i < input.length();i++){
        if(input[i]=='{')
            x++;
        else if(input[i]=='}')
            y++;
    }
    return x-y;
}

int main() {
    
}
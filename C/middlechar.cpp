/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Exercise 5.6

Returns middle character of a string if odd, or both mid chars if even
*/

#include <iostream>
using namespace std;

string middle(string str){
    if(str.length()%2==0)
        return str.substr((str.length()/2)-1,2);
    else
        return str.substr(str.length()/2,1);
}
int main(){
    string x;
    cout<<"Enter a string: ";
    cin >>x;
    cout<<"String middle: ";
    cout<<middle(x);
    return 0;
}
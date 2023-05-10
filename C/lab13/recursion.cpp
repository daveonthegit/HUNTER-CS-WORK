/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 13

Recursion

*/

#include <iostream>
#include <cstring>
using namespace std;

void printRange(int left, int right){
    if(left<=right){
        cout<<left<<" ";
        printRange(left+1,right);
    }
}

int sumRange(int left, int right){
    if(left>right){
        return 0;
    }
    if(left==right){
        return left;
    }
    return left +sumRange(left+1,right);

}
int sumArray(int arr[],int size){
    if(size ==1){
        return arr[size-1];
    }
    return arr[size-1]+sumArray(arr,size-1);
}
bool isAlphanumeric(string s){
    if(s==""){
        return true;
    }
    if(isalnum(s[0])){
        return isAlphanumeric(s.substr(1,s.length()-1));
    }
    return false;
}

bool nestedParens(string s){
    if(s==""){
        return true;
    }
    if(s[0]=='('||s[0]==')'){
        return nestedParens(s.substr(1,s.length()-1));
    }

    return false; 
}
int main(){
    printRange(-2,10);
    cout<<sumRange(1,3)<<endl;
    int arr[] = {1, 2, 3};
    int size = 3; 
    cout<<sumArray(arr,3)<<endl;
    cout << nestedParens("((()))") << endl;      // true (1)
    cout << nestedParens("()") << endl;          // true (1)
    cout << nestedParens("") << endl;            // true (1)

    cout << nestedParens("(((") << endl;         // false (0)
    cout << nestedParens("(()") << endl;         // false (0)
    cout << nestedParens(")(") << endl;          // false (0)
    cout << nestedParens("a(b)c") << endl;       // false (0)
}
/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab1A

prints out smaller of the three
*/

#include <iostream>
using namespace std;

int main() {
    int x; int y; int z;/*initialization, initializes x y and z */
    cout << "Enter the first number: "; //setting x using input
    cin >> x;
    cout << "Enter the second number: ";//setting y using input
    cin >> y;
    cout << "Enter the third number: ";//setting z using input
    cin >> z;
    cout << "The smaller of the three is ";//outputting largest
    if (x <y) {  /*uses logic of x <y then compare x to z, or if y < x, then compare y to z*/
        if (x <z) {
            cout << x;
        } else {
            cout << z;
        }
    } else{
        if (y<z){
            cout << y;
        } else {
            cout << z;
        }
    }
    return 0;
}
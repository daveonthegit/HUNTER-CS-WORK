/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab1A

prints out smaller of the two
*/

#include <iostream>
using namespace std;

int main() {
    int x; int y;/*initialization, initializes x and y */
    cout << "Enter the first number: ";//setting x using input
    cin >> x;
    cout << "Enter the second number: ";//setting y using input
    cin >> y;
    cout << "The smaller of the two is ";//output
    if (x <y) { //logic
        cout << x;
    } else{
        cout << y;
    }
    return 0; /*returns 0 */
}
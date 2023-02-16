/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Homework Exercise 2.10

prints out cost per 100 miles and how far car can go.
*/

#include <iostream>
using namespace std;

int main(){
    int gallons; int mpg; float price; // initializes int for gallons and mpg, and price as a  float.
    cout<< "Please input # gallons: "; //requests for # gallons, and sets.
    cin >> gallons;
    cout<<"Please input # mpg: "; //requests for # mpg, and sets.
    cin >> mpg;
    cout<< "Pleas input price per gallon: "; //requests for price, and sets.
    cin >> price;
    float total = (100/(float)mpg) *price; //calculates total for 100 miles
    cout << total <<"$ per 100 miles."; //prints total for 100 miles
    cout << "The car can go " << gallons*mpg<< "miles with your current gas"; // prints mileage.
    return 0;
}

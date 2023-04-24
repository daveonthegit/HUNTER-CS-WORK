/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Quiz 10

*/

#include <iostream>
#include <cstring>
using namespace std;


class Date {
public:
    int month;
    int day;
    int year;
};

string formatDate(Date* d){
    string months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    return months[d->month]+" "+to_string(d->day)+", "+to_string(d->year);
}

int main(){
    Date midterm1 = Date {10,17,2022};
    cout<<formatDate(&midterm1)<<endl;
    Date christmas = Date {12,25,2022};
    cout<<formatDate(&christmas)<<endl;
    return 0;
}
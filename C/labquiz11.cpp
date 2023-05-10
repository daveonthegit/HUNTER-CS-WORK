/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: labquiz 11

quiz
*/

#include <iostream>
using namespace std;
class Money{
public:
    int dollars;
    int cents;

};
Money withdraw_money(Money balance, Money withdrawal){
    balance.dollars-=withdrawal.dollars;
    balance.cents-=withdrawal.cents;
    if(balance.cents<0){
        balance.cents+=100;
        balance.dollars-=1;
    }
    if(balance.dollars<0){
        balance.dollars=0;
        balance.cents=0;
    }
    return balance;
}

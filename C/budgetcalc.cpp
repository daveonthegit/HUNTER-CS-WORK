//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  12/5/22
//calculates annual budget

#include <iostream>
using namespace std; 

int main(){
    double budget;
    double expense;
    cout << "Input your annual budget: ";
    cin >> budget;
    cout << "Input your month expense: ";
    cin >> expense;
    cout << "month	expense	remaining balance of budget\n";
    for (int i = 1; i<13;i++){
        if(i==7){
            expense*=1.15;
        }
        budget-=expense;
        printf("%5d\t%7.2f\t%27.2f\n", i, expense, budget);
    }
    if(budget<0){
        cout <<"need higher budget";
    }
    return 0;
}
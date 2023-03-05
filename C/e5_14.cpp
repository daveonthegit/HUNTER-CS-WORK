//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  2/27/23
//Assignment E5.14
//Sorts two variables into sorted order.

#include <iostream>
using namespace std;

void sort2(int& a, int& b){
    int temp = a;
    if(b<a){
        a = b;
        b =temp;
    }
}

int main(){
    int x,y;
    cout<< "Please enter two numbers with white space between: ";
    cin>>x>>y;
    sort2(x,y);
    cout<<x<<" "<<y<<endl;
    return 0;
}
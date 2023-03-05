//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  2/27/23
//Assignment E5.15
//Sorts three variables into sorted order.

#include <iostream>
using namespace std;

void sort2(int& a, int& b){
    int temp = a;
    if(b<a){
        a = b;
        b =temp;
    }
}

void sort3(int& a, int&b, int&c){
    sort2(b,c);
    sort2(a,b);
    sort2(b,c);
}

int main(){
    int x,y,z;
    cout<< "Please enter three numbers with white space between: ";
    cin>>x>>y>>z;
    sort3(x,y,z);
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}
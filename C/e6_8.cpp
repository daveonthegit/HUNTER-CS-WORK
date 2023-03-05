//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  2/27/23
//Assignment E6.8
//checks two arrays to see if they are equal

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size){
    if (a_size!= b_size){
        return false;
    }
    for (int i = 0; i<a_size;i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int main(){
    return 0;
}
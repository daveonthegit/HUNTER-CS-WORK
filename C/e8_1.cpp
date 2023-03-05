//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  2/27/23
//Assignment E8.1
//opens hello world txt, writes to it, and then outputs the txt contents.

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream helloworld("hello.txt");
    if(helloworld.is_open()){
        helloworld<<"Hello, World!";
        helloworld.close();
    }else{
        cout<<"unable to open file";
    }
    string line;
    ifstream helloin("hello.txt");
    if(helloin.is_open()){
        while(getline(helloin, line)){
            cout<<line<<endl;
        }
        helloin.close();
    }else{
        cout<<"unable to open file";
    }

    return 0;
}
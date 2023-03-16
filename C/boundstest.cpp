#include <iostream>
using namespace std;
int funct(int x){
    cout<<x<<endl;
}

int sobel(int a, int b, int c, int g, int h, int i){
    int sob = (g+2*h+i)-(a+2*b+c);
    if(sob>255){
        sob = 255;
    }else if (sob <0){
        sob = 0;
    }
    return sob;
}
int main() {
    int arra[] = {3,2,1,5};
    cout<<sobel(0,0,0,0,11,22)<<endl;
    funct(arra[-1]);
    funct(arra[0]);
}
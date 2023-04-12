/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Exercise 9.5

rectangle
*/
#include <iostream>
using namespace std;

class Rectangle{
    public:
        Rectangle(double input_w, double input_h){
            width = input_w;
            height = input_h;
        }

        double get_perimeter(){
            return (2*width)+(2*height);
        }
        double get_area(){
            return width*height;
        }
        void resize(double factor){
            width*=factor;
            height*=height;
        }
    private:
        double width;
        double height;
};

int main(){
    double w; double h;
    cout<<"enter: ";
    cin>>w>>h;
    Rectangle test(w,h);
    cout<<test.get_area();
}

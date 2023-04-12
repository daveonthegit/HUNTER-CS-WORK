/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Homework E7.16 - Point Distance

Triangle struct, uses three point members, reads coordinates of each, then calculates perimeter.
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x;
    double y;
};

double distance(Point a, Point b){
    return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
}

struct Triangle{
    Point p1;
    Point p2;
    Point p3;
};
double perimeter(Triangle t){
    return distance(t.p1,t.p2)+distance(t.p2,t.p3)+distance(t.p3,t.p1);
}


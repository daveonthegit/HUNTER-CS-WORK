/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 9.1

Calculate distance of a point from origin in 3d space.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D* new_point = new Coord3D;
    new_point->x = x;
    new_point->y = y;
    new_point-> z= z;

    return new_point;
}
void deleteCoord3D(Coord3D *p){
    delete p;
}

double length(Coord3D *p){
    return sqrt(pow(p->x,2)+pow(p->y,2)+pow(p->z,2));
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    if(length(p1)>length(p2))
        return p1;
    return p2;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x = ppos->x+ pvel->x*dt;
    ppos->y = ppos->y+ pvel->y*dt;
    ppos->z = ppos->z+ pvel->z*dt;
}

int main() {
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};
    cout << length(&pointP) << endl; // would print 37.4166
    cout << length(&pointQ) << endl; 
    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl; // So which point is farther?
    
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // object pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}
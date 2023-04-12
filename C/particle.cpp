/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 9 F

Create Particle Class
*/

#include <iostream>
using namespace std;

class Particle{
public:
    double x, y, z, vx, vy ,vz;
};

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz){
    Particle* newParticle = new Particle;
    newParticle->x = x;
    newParticle->y = y;
    newParticle->z = z;
    newParticle->vx = vx;
    newParticle->vy = vy;
    newParticle->vz=vz;
    return newParticle;
}
class Coord3D {
public:
    double x;
    double y;
    double z;
};
Coord3D getPosition(Particle *p){
    Coord3D newPoint;
    newPoint.x= p->x;
    newPoint.y = p->y;
    newPoint.z = p-> z;
    return newPoint;
}
void move(Particle *p, double dt){
    p->x = p->x +p->vx*dt;
    p->y = p->y +p->vy*dt;
    p->z = p->z +p->vz*dt;

}
void setVelocity(Particle *p, double vx, double vy, double vz){
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}
void deleteParticle(Particle *p){
    delete p;
}



int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}
#pragma once

#include "../DataStructures/XYPair.h"
#include "../DataStructures/Vector2.h"
#include "ofMain.h"
#include <vector>

class Planet{
    private:
        double radius;
        double mass;
        XYPair* position;
        Vector2* velocity;
        vector<XYPair*> past;
        double constantG;
    public:
        Planet(double, double, XYPair*, Vector2*, double);
        double getMass(){return mass;}
        double getRadius(){return radius;}
        void draw();
        void updateVelocity(Planet*);
        void updatePosition();
        XYPair* getPosition(){return position;}
        double distanceTo(Planet* other){return position->distanceTo(other->getPosition());}
        void print(){
            std::cout << "Radius : " << radius << "; ";
            std::cout << "Mass : " << mass << "; ";
            std::cout << "Position : " << position->x() << ", " << position->y() << "; ";
            std::cout << "Velocity : " << velocity->magnitude() << "; ";
            std::cout << std::endl;
        }
};


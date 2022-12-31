#pragma once

#include "XYPair.h"
#include <math.h>


class Vector2 : XYPair{
public:
    Vector2(double x, double y) : XYPair(x, y){}
    Vector2(XYPair* xyPair):XYPair(xyPair->x(), xyPair->y()){}
    Vector2(XYPair* a, XYPair* b):XYPair(b->x()-a->x(), b->y() - a->y()){}
    double magnitude(){
        return sqrt(pow(x(), 2)+pow(y(), 2));
    }
    void toUnitMagnitude(){
        scale(1/magnitude());
    }
    void scale(double scaleFactor){
        x(x()*scaleFactor);
        y(y()*scaleFactor);
    }

    void add(Vector2* other){
        XYPair::add((XYPair*)other);
    }
};



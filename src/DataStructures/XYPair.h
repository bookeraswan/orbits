#pragma once
#include <math.h>


class XYPair{
    private:
        double xy[2];
    public:
        XYPair(double, double);

        double  x();
        double  y();

        void x(double);
        void y(double);

        void add(XYPair* other){
            x(x() + other->x());
            y(y() + other->y());
        }

        double distanceTo(XYPair* other){
            return sqrt(pow(x()-other->x(), 2) + pow(y()-other->y(), 2));
        }

        XYPair* copy();
};

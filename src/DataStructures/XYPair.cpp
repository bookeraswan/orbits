#include "XYPair.h"

XYPair::XYPair(double xValue, double yValue){
    this->xy[0] = xValue;
    this->xy[1] = yValue;
}

double  XYPair::x(){return xy[0];}
double  XYPair::y(){return xy[1];}

void  XYPair::x(double value){xy[0] = value;}
void  XYPair::y(double value){xy[1] = value;}

XYPair* XYPair::copy(){
    return new XYPair(xy[0], xy[1]);
}

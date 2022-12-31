#include "Planet.h"
#include "ofMain.h"


Planet::Planet(double radius, double mass, XYPair* position, Vector2* velocity, double constantG){
    this->radius = radius;
    this->mass   = mass;
    this->position = position;
    this->velocity = velocity;
    this->constantG = constantG;
}

void Planet::draw(){
    for(int i = 0; i < past.size(); i++){
        ofColor color;
        color.r = i;
        color.g = i;
        color.b = i;
        ofSetColor(color);
        ofFill();
        ofDrawCircle(past[i]->x(), past[i]->y(), radius);
    }
    ofColor color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    ofSetColor(color);
    ofFill();
    ofDrawCircle(position->x(), position->y(), 2*radius);
}

void Planet::updateVelocity(Planet* other){
    double distSquared = pow(this->distanceTo(other), 2);
    Vector2* acceleration = new Vector2(position, other->getPosition());
    acceleration->toUnitMagnitude();
    acceleration->scale(constantG*other->getMass()/distSquared);
    velocity->add(acceleration);
}

void Planet::updatePosition(){
    past.push_back(new XYPair(position->x(), position->y()));
    position->add((XYPair*)velocity);
    if(past.size() > 254){
        past.erase(past.begin(), past.begin()+1);
    }
}

#include "ofApp.h"
#include <math.h>

#include "DataStructures/XYPair.h"
#include "DataStructures/Vector2.h"
#include <vector>

vector<double> split(string s){
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    vector<double> output = vector<double>();
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        output.push_back(stod(token));
        s.erase(0, pos + delimiter.length());
    }
    output.push_back(stod(s));
    return output;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    vector <vector<double>> p;
    double constantG;
    ofBuffer buffer = ofBufferFromFile(file);
    bool firstLine = true;
    for (auto line : buffer.getLines()){
        if(firstLine){
            constantG = stod(line);
            firstLine = false;
        }
        else p.push_back(split(line));
    }

    for(vector<double> pd : p){
        planets.push_back(new Planet(pd[0], pd[1], new XYPair(ofGetWidth()/2 + pd[2], ofGetHeight()/2 + pd[3]), new Vector2(pd[4], pd[5]), constantG));
    }
    std::cout << planets.size() << std::endl;
    for(Planet* planet : planets){
        planet->print();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < (int)planets.size(); i++){
        for(int j = 0; j < (int)planets.size(); j++){
            if(i == j) continue;
            planets[i]->updateVelocity(planets[j]);
        }
    }
    for(int i = 0; i < (int)planets.size(); i++){
        planets[i]->updatePosition();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < (int)planets.size(); i++){
        planets[i]->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

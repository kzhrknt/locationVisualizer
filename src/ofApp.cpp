#include "ofApp.h"

double x, y;
double loc_x, loc_y;
double radius;

int i;
int j = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    
    //setting - window, draw
    ofBackground(255, 255, 255, 0);
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetFrameRate(5);
    
    //initialize current position icon
    x = 100;
    y = 100;
    radius = 4;
    
    //loadImage
    myImage.loadImage("/Users/kz/Project/Lab/MasterProgram/visualize/of/of_v0.8.4_osx_release/apps/myApps/locationVisualizer/img/bg-real.jpg");
    myProf.loadImage("/Users/kz/Project/Lab/MasterProgram/visualize/of/of_v0.8.4_osx_release/apps/myApps/locationVisualizer/img/child-girl.png");

    //load csv file
    csv.loadFile(ofToDataPath("/Users/kz/Project/Lab/MasterProgram/visualize/of/of_v0.8.4_osx_release/apps/myApps/locationVisualizer/data/09_18_2014.csv"));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    stringstream ss;
    
    int numRows = csv.numRows;
    double x_array[numRows];
    double y_array[numRows];
    
    for (i = 0; i < csv.numRows-1 ; i++) {
        
        //debug area------------------------------------//
        string sx = csv.data[i+1][0];
        sx.erase(sx.begin()+0);
        sx.erase( --sx.end());
        istringstream isx;
        isx.str(sx);
        double x;
        isx >> x;
        x_array[i] = x;
        
        //debug area------------------------------------//
        string sy = csv.data[i+1][1];
        sy.erase(sy.begin()+0);
        sy.erase( --sy.end());
        istringstream isy;
        isy.str(sy);
        double y;
        isy >> y;
        y_array[i] = y;
        
//        cout << "(x, y) = (" << x << "," << y << ")" << endl;
//        cout << "(x, y) = (" << x_array[i] << "," << y_array[i] << ")" << endl;

    }
    
    loc_x = x_array[j];
    loc_y = y_array[j];
    
    cout << "(x, y) = (" << loc_x << "," << loc_y << ")" << endl;
    
    j++;
    
    if (j > csv.numRows) {
        OF_EXIT_APP(0);
    }


}

//--------------------------------------------------------------
void ofApp::draw(){

    //draw background image.
    myImage.draw(0, 0, 1000, 1000);
    
    cout << loc_x*250 << endl;
    cout << loc_y*250 << endl;
    
    ofFill();
    radius = 18;

    //estimated location error - depend on CDLocationProximity
    ofSetColor(19, 131, 255, 30);
    ofCircle(loc_x*250, loc_y*250, radius+100);
    
    //icon
    ofSetColor(255, 255, 255);
    myProf.draw(loc_x*250 - 50, loc_y*250 - 50, 100 ,100);
    
    //enclose estimated location with white line
    ofSetColor(255, 255, 255);
    ofNoFill();
    ofSetLineWidth(4);
    ofCircle(loc_x*250, loc_y*250, 50);

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

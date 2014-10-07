#pragma once

#include "ofMain.h"
#include "ofxCsv.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace wng;
using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    
        wng::ofxCsv csv;
        wng::ofxCsv csvRecorder;
    
        ofImage myImage;
        ofImage grabbedImage;
        ofImage myProf;
    
    
    inline int toInt(std::string s) {int v; std::istringstream sin(s);sin>>v;return v;}
    template<class T> inline std::string toString(T x) {std::ostringstream sout;sout<<x;return sout.str();}
    
    
};


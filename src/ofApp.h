#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"
#include <array>
#include <vector>

using namespace glm;

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofMesh mesh;
        ofTexture texture;
        ofxAssimpModelLoader model;
        
        ofParameter<bool> wireframe;
//        ofxButton chromatic;
//        ofxButton crash;
//        ofxButton wavy;
    
        vector<ofxButton> filters;
    
        array<ofParameter<bool>, 5> toggle;
        array<bool, 5> triggered = {false};
    
    
        ofParameter<ofColor> color;
        ofParameter<float> twistFactor;
        ofParameter<float> size;
        
        ofxPanel gui;
            
        // 2D Filters
        //ofFbo filters;
        
        // 3D Effects
        ofFbo fbo;
        
        ofShader render;
        ofShader twist;
        ofEasyCam camera;
    
        ofShader postProcessing;
    
        ofShader crash;
        ofShader chromaticAbberation;
        ofShader wavy;
        ofShader pixelated;
        ofShader depth;
    
    
        bool set = false;
    
};

#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

#define GRABBER_WIDTH 640
#define GRABBER_HEIGHT 480

class ofApp : public ofBaseApp {

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void mousePressed(int x, int y, int button);

        ofVideoGrabber grabber;

        ofxCvColorImage rgbImage;

        ofxCvColorImage hsvImage;

        ofxCvGrayscaleImage hueImage;
        ofxCvGrayscaleImage satImage;
        ofxCvGrayscaleImage valImage;
};

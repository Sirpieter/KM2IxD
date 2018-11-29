#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "BlobTracker.h"

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
        BlobTracker blobTracker;

        bool showHueAndFilter = true;
        bool showBlobs = true;
        bool showContours = true;
};

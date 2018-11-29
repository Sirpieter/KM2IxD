#pragma once

#include "ofxOpenCv.h"

class BlobTracker {
    public:
        BlobTracker();
        void setup(ofVideoGrabber* grabber);
        void update();

        void selectHue(float x, float y);


        void setHueMargin(int hueMargin) {
            this->hueMargin = hueMargin;
        }

        void drawHueImage(float x = 0, float y = 0, int width = 0, int height = 0);
        void drawFilteredImage(float x = 0, float y = 0, int width = 0, int height = 0);
        void drawBlobs(float x, float y, int width, int height);
        void drawContours(float x, float y, int width, int height);
    private:
        ofVideoGrabber* grabber;
        float width;
        float height;

        ofxCvColorImage cameraImage;
        ofxCvGrayscaleImage hue;
        ofxCvGrayscaleImage filteredImage;

        ofxCvContourFinder contours;

        int selectedHue = -1;
        int hueMargin = 10;
};


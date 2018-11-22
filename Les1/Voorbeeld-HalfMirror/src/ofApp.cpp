#include "ofApp.h"

void ofApp::setup() {
    grabber.listDevices();

    grabber.setDeviceID(0);
    grabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);
    grabber.setDesiredFrameRate(30);

    workspace.allocate(CAM_WIDTH, CAM_HEIGHT, OF_IMAGE_COLOR);
}

void ofApp::update() {
    grabber.update();

    if (grabber.isFrameNew()) {
        ofPixels& pixels = grabber.getPixels();
        for (size_t y = 0; y < pixels.getHeight(); y++) {
            for (size_t x = 0; x < pixels.getWidth()/2; x++) {

                ofColor col = pixels.getColor(drawLeft ? x : pixels.getWidth() - x, y);

                workspace.setColor(x, y, col);
                workspace.setColor(pixels.getWidth() - x, y, col);
            }
        }

        image.setFromPixels(workspace);
        image.mirror(false, true);
    }
}

void ofApp::draw() {
    // draw the manipulated image, scaled up 3 times
    image.draw(0, 0, CAM_WIDTH * 3, CAM_HEIGHT * 3);
}

void ofApp::keyPressed(int key) {
    if (key == ' ') {
        drawLeft = !drawLeft;
    }
}

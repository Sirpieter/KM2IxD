#include "ofApp.h"

void ofApp::setup() {
    ofBackground(ofColor::black);
    grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT, true);
    blobTracker.setup(&grabber);
}

void ofApp::update() {
    grabber.update();
    blobTracker.update();
}

void ofApp::draw() {
    grabber.draw(ofGetWidth(), 0, -ofGetWidth(), ofGetHeight());

    if (showHueAndFilter) {
        blobTracker.drawHueImage(0, 0);
        blobTracker.drawFilteredImage(GRABBER_WIDTH, 0);
    }

    if (showContours) blobTracker.drawContours(0, 0, ofGetWidth(), ofGetHeight());
    if (showBlobs) blobTracker.drawBlobs(0, 0, ofGetWidth(), ofGetHeight());
}

void ofApp::keyPressed(int key) {
    if (key == ' ') {
        showHueAndFilter = !showHueAndFilter;
        cout << "yes" << showHueAndFilter << endl;
    } else if (key == 'b') {
        showBlobs = !showBlobs;
    } else if (key == 'c') {
        showContours = !showContours;
    }
}

void ofApp::mousePressed(int x, int y, int button) {
    if (showHueAndFilter) {
        blobTracker.selectHue(x, y);
    }
}

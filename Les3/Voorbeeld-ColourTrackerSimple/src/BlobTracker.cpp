#include "BlobTracker.h"

BlobTracker::BlobTracker() {}

void BlobTracker::setup(ofVideoGrabber* grabber) {
    this->grabber = grabber;

    width = grabber->getWidth();
    height = grabber->getHeight();

    cameraImage.allocate(width, height);
    hue.allocate(width, height);
    filteredImage.allocate(width, height);
}

void BlobTracker::update() {
    if (grabber->isFrameNew()) {
        cameraImage.setFromPixels(grabber->getPixels());
        cameraImage.mirror(false, true);
        cameraImage.convertRgbToHsv();
        cameraImage.convertToGrayscalePlanarImage(hue, 0); // only interested in hue

        for (int i = 0; i < width * height; i++) {
            if (ofInRange(hue.getPixels()[i], selectedHue - hueMargin, selectedHue + hueMargin)) {
                filteredImage.getPixels()[i] = 255; // make white
            } else {
                filteredImage.getPixels()[i] = 0; // make black
            }
        }
        filteredImage.flagImageChanged();

        contours.findContours(filteredImage, 50, width * height / 2, 1, false);
    }
}

void BlobTracker::drawBlobs(float x, float y, int width, int height) {
    ofSetColor(ofColor::blue, 100);
    ofFill();
    for (auto& blob : contours.blobs) {
        ofDrawCircle(blob.centroid.x * width / this->width,
                     blob.centroid.y * height / this->height,
                     20);
    }
    ofSetColor(ofColor::white);
}

void BlobTracker::selectHue(float x, float y) {
    if (x * y < hue.getPixels().size()) {
        selectedHue = hue.getPixels()[y * width + x];
    }
}

void BlobTracker::drawContours(float x, float y, int width, int height) {
    contours.draw(x, y, width, height);
}

void BlobTracker::drawFilteredImage(float x, float y, int width, int height) {
    filteredImage.draw(x, y);
    if (width == height == 0) {
        filteredImage.draw(x, y);
    } else {
        filteredImage.draw(x, y, width, height);
    }
}

void BlobTracker::drawHueImage(float x, float y, int width, int height) {
    cameraImage.draw(x, y);
    if (width == height == 0) {
        cameraImage.draw(x, y);
    } else {
        hue.draw(x, y, width, height);
    }
}

#pragma once


#include "ofMain.h"

//step 6: Include the head file of ofOpenCv
#include "ofxOpenCv.h"


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
		
    //step2: Member objects/variables for webcam video grabber
    ofVideoGrabber mVidGrabber;
    int mCamWidth;
    int mCamHeight;
    
    //step 7: Member objects/variables for openCV
    //Image storages in openCV format:
    ofxCvColorImage mColorImg;
    ofxCvGrayscaleImage mGrayImage;
    ofxCvGrayscaleImage mGrayBg;
    ofxCvGrayscaleImage mGrayDiff;
    ofPixels pixels;
    
    // for blob dectection:
    ofxCvContourFinder mContourFinder;
    
    int mThreshold; //Threshold for the difference image
    bool mLearnBackground; // Indicates whether the background of image for difference needs updating
};

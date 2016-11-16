#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // step 3: setup video grabber
    ofBackground(128);
    
    mCamWidth = 320;
    mCamHeight = 240;
    
    mVidGrabber.setDeviceID(0);
    mVidGrabber.setDesiredFrameRate(60);
    mVidGrabber.initGrabber(mCamWidth, mCamHeight);
    
    //step 8: Setup openCV objects/variables
    mColorImg.allocate(mCamWidth, mCamHeight);
    mGrayImage.allocate(mCamWidth, mCamHeight);
    mGrayBg.allocate(mCamWidth, mCamHeight);
    mGrayDiff.allocate(mCamWidth, mCamHeight);
    
    mThreshold = 80;
    mLearnBackground = true;
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //step4: grab data from webcam
    mVidGrabber.update();
    
    //step 9: computer vision
    //only do this when there is a new frame from webcam
    if(mVidGrabber.isFrameNew()){
        // convert the webcam image to openCV format
        
        mColorImg.setFromPixels(mVidGrabber.getPixels());
        
        // convert ofxCvColorImage to ofxCvGrayscaleImage (3channels ->1channel),so that we can do math on it easily.
        mGrayImage= mColorImg;
        
        if (mLearnBackground== true){//need to update difference background
            mGrayBg =mGrayImage;
            mLearnBackground = false;
        }
        //take the absolute valuse of the difference bet background and current frame, ans then threshold;
        mGrayDiff.absDiff(mGrayBg, mGrayImage);
        mGrayDiff.threshold(mThreshold);//pixels that has value >=mThreshold become white(255); others become black (0).
        pixels = mGrayDiff.getPixels();
        for(int i = 0;i<mGrayDiff.getPixels().size(); i++){
            if(pixels.getColor(i)!=ofColor(255)){
                pixels.setColor(i, ofColor(ofRandom(255),ofRandom(255),0));
            }
        }
        mGrayDiff.setFromPixels(pixels);
        mContourFinder.findContours(mGrayDiff, 20, (mCamWidth*mCamHeight)/3, 3, 20,true);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for(int i=0 ; i<mCamWidth;i+=10 ){
        for(int j = 0; j<mCamHeight ; j+=10){
            ofSetColor(mVidGrabber.getPixels().getColor(i, j));
            ofDrawRectangle(i+30, j+30, 10, 10);
        }
    }

    //ofSetColor(200, 134, 242);
    //step 5: draw webcam image
    ofSetColor(255);
//   mVidGrabber.draw(20, 20);
    
//    step 10: draw openCV results
    mGrayImage.draw(360,20);
    mGrayBg.draw(20,280);
    mGrayDiff.draw(360,280);
    

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

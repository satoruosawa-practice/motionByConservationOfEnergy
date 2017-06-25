#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  //  ofSetVerticalSync(false);
  //  ofSetFrameRate(0);
  ofBackground(63);
  
  app_time_ = AppTime();
  sphere_ = Sphere(app_time_);
}

//--------------------------------------------------------------
void ofApp::update(){
  app_time_.update();
  sphere_.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofDrawGrid(PX_PER_METER, 11, false, false, false, true);
  
  sphere_.draw();
  
  ofDrawBitmapString("frameRate: " +
                     ofToString(ofGetFrameRate(), 1) +
                     " fps",
                     10, 20);
  ofDrawBitmapString("time: " +
                     ofToString(app_time_.getElapsedTimeS(), 1) +
                     " s",
                     200, 20);
  sphere_.drawParameters();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch(key) {
    case OF_KEY_RIGHT:
    {
      float dx = 1.0;  // m
      float force = 1.0;  // N
      sphere_.doWork(force, dx);
    }
      break;
    case 'c':
      sphere_.reset();
      break;
    default:
      break;
  }
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

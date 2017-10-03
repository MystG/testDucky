#include "ofApp.h"

bool duckAngry = false;
//set up the background color
ofColor yellowColor(255, 244, 165);
ofColor darkerYellowColor(132, 116, 76);

//--------------------------------------------------------------
void ofApp::setup(){
	// images of ducky moving and ducky yelling
	ducky.load("images/duck-1.png");
	duckyYell.load("images/duck-2.png");

	// chicken dance music
	chickenDancePiece.load("Chicken Dance Song.mp3");
	chickenDancePiece.setLoop(true);
	chickenDancePiece.setVolume(0.5);
	chickenDancePiece.play();

	// quack sound effect
	quack.load("Quack Sound Effect  Gutlacky.mp3");
	quack.setLoop(true);
	quack.setVolume(0.2);
	quack.play();

	// duck yelling sound effect
	duckYell.load("Daffy duck screaming sound effects.mp3");
	duckYell.setLoop(true);
	duckYell.setVolume(0.3);
	duckYell.play();
	duckYell.setPaused(true);


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(yellowColor, darkerYellowColor, OF_GRADIENT_CIRCULAR);

	// if not clicking, duck is calm
	if (!duckAngry) {
		ducky.draw((ofGetWidth() / 2) - 212.5 / 2,
			(ofGetHeight() / 2) - 237.5 / 2,
			212.5, 237.5);
	}
	//duckyYell.mirror(false, true);
	// if clicking, duck is yelling/angry 
	else if (duckAngry) {
		duckyYell.draw((ofGetWidth() / 2) - 212.5 / 2,
			(ofGetHeight() / 2) - 237.5 / 2,
			212.5, 237.5);
	}
	ofDrawBitmapString("No Touchy Please", ofGetWidth()/2 - 60, ofGetHeight()/2 - 200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	// flip the image vertically so that it looks the other way
	if (x < ofGetWidth() / 2) {
		ducky.mirror(false, true);
	}
	else {
		ducky.mirror(false, true);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if ((x < ofGetWidth() / 2 + 120) && (x > ofGetWidth() /2 - 120)) {
		if ((y < ofGetHeight() / 2 + 130) && (y > ofGetHeight() / 2 - 130)) {
			// if mouse clicked, duck is angry, quacking stops, and yelling commences
			duckAngry = true;
			quack.setPaused(true);
			duckYell.setPaused(false);
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	// if mouse released, duck is calm, quacking begins, and yelling ceases
	duckAngry = false;
	quack.setPaused(false);
	duckYell.setPaused(true);
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

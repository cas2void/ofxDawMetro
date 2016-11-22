#include "ofApp.h"

void ofApp::onBarEvent(int & bar) {
}

void ofApp::onBeatEvent(int & beat) {
	// play tic on the first beat of a bar
	if (beat == 1) {
		tic.play();
	}
	else {
		tac.play();
	}
}

void ofApp::onSixteenthEvent(int & sixteenth) {
}

void ofApp::bpmChanged(float & value) {
	metro.setBpm(value);
	metro.resetTimer();
}

void ofApp::activeChanged(bool & value) {
	if (value) {
		metro.start();
	}
	else {
		metro.stop();
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	// add bar/beat/sixteenth listener on demand
	metro.addBeatListener(this);
	//metro.addBarListener(this);
	//metro.addSixteenthListener(this);

	gui.setup();
	bpm.addListener(this, &ofApp::bpmChanged);
	gui.add(bpm.set("BPM", 120, 30, 240));
	active.addListener(this, &ofApp::activeChanged);
	gui.add(active.set("Active", false));

	metro.setBpm(bpm);
	tic.load("sound/tic.wav");
	tac.load("sound/tac.wav");

	font.load("font/consola.ttf", 48);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	std::string timePos = ofToString(metro.getBar(), 3, ' ') + " : " + ofToString(metro.getBeat()) + " : " + 
		ofToString(metro.getSixteenth());

	font.drawString(timePos, 10, 150);

	gui.draw();
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

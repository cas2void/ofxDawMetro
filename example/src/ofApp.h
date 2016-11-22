#pragma once

#include "ofMain.h"
#include "ofxDawMetro.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp, public ofxDawMetro::MetroListener {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	// overide ofxDawMetro::MetroListener's method if necessary
	void onBarEvent(int & bar) override;
	void onBeatEvent(int & beat) override;
	void onSixteenthEvent(int & sixteenth) override;

	ofxDawMetro metro;
	ofSoundPlayer tic, tac;
	ofTrueTypeFont font;

	ofxPanel gui;
	ofParameter<float> bpm;
	ofParameter<bool> active;

	void bpmChanged(float & value);
	void activeChanged(bool & value);
};

/*
 *  ofxGameOfLife.h
 *
 *
 *  Created by Chris Roby on 3/26/10.
 *  Adapted to ofxaddon by Bernardo Rodrigues on 09/27/18.
 *
 *  Copyright (c) 2018 Chris Roby & Bernardo Rodrigues. All rights reserved.
 *
 */
#pragma once

#include "ofMain.h"
#include "ofxGameOfLife.h"

class ofApp : public ofBaseApp{
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

		ofxGameOfLife game;
};

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int cellSize = 6;

    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
    game.gliderGun(ofGetWidth()/3/cellSize, ofGetHeight()/2/cellSize);
}

//--------------------------------------------------------------
void ofApp::update(){
    game.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    int cellWidth = 6;
    int cellHeight = 6;

    for (int i=0; i<game.getCols(); i++) {
		for (int j=0; j<game.getRows(); j++) {
            cell thisCell = game.getCell(i, j);
			ofSetColor(150, 150, 150);
			ofNoFill();
			ofRect(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
            if (thisCell.currState == true) {
				ofSetColor(thisCell.color.r, thisCell.color.g, thisCell.color.b);
				ofFill();
				ofRect(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
				ofNoFill();
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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

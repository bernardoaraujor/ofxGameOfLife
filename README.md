ofxGameOfLife
=====================================

[openFrameworks addon](http://ofxaddons.com/) of [Conway's Game of Life](http://en.wikipedia.org/wiki/Conway's_Game_of_Life).

I'm working on a terminal-based Game of Life oF app, so I thought having a general purpose ofx implementation would be useful. This addon is based on [Chris Roby](http://github.com/croby)'s implementation, which can be found at https://github.com/croby/conway-of.

The main abstraction of ofxGameOfLife is the grid system. The grid can be retrieved with `game.getGrid()`, while individual cells can be retrieved with `game.getCell(i, j)`.

Released under the [MIT License](https://en.wikipedia.org/wiki/MIT_License).

Developed and tested under openFrameworks v0.10.0 on Ubuntu 16.04.

Example:
![image](http://upload.wikimedia.org/wikipedia/commons/e/e5/Gospers_glider_gun.gif)

[source](http://en.wikipedia.org/wiki/File:Gospers_glider_gun.gif)

declare ofxGameOfLife at `ofApp.h`:
```
ofxGameOfLife game;
```

then setup the game, update and draw at `ofApp.cpp`:
```
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
```

Contact: bernardoaraujor@gmail.com

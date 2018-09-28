/*
 *  ofxGameOfLife.cpp
 *
 *
 *  Created by Chris Roby on 3/26/10.
 *  Adapted to ofxaddon by Bernardo Rodrigues on 09/27/18.
 *
 *  Copyright (c) 2018 Chris Roby & Bernardo Rodrigues. All rights reserved.
 *
 */

#include "ofxGameOfLife.h"

ofxGameOfLife::ofxGameOfLife(){
}

ofxGameOfLife::~ofxGameOfLife(){
    clear();
}

void ofxGameOfLife::setup(int width, int height, int cellSize){
    active = true;
    cols = width/cellSize;
    rows = height/cellSize;

    if (width % cellSize != 0 || (height & cellSize) != 0) {
        float ratio = width/height;
        cellWidth = cellSize * ratio;
        cellHeight = cellSize;
    } else {
        cellWidth = cellSize;
        cellHeight = cellSize;
    }

    // set up grid
    clear();
}

void ofxGameOfLife::update(){
    if (ofGetFrameNum() % TICK_INTERVAL == 0 && active) {
        tick();
    }
}

void ofxGameOfLife::tick() {
	// get active neighbors for each cell
	for (int i=0; i<cols; i++) {
		for (int j=0; j<rows; j++) {
      cell *thisCell = &grid[i][j];
			thisCell->activeNeighbors = getNumActiveNeighbors(i, j);
      bool currState = thisCell->currState;
      int activeNeighbors = thisCell->activeNeighbors;

			if (currState == true && activeNeighbors < 2) {
        thisCell->nextState = false;
      } else if (currState == true && activeNeighbors > 3) {
        thisCell->nextState = false;
      } else if (currState == true && activeNeighbors > 1 && activeNeighbors < 4) {
        thisCell->nextState = true;
        thisCell->color = ofColor::black;
      } else if (currState == false && activeNeighbors == 3) {
        thisCell->nextState = true;
        thisCell->color = highlight ? ofColor::green : ofColor::black;
      }
		}
	}
	makeNextStateCurrent();
}

void ofxGameOfLife::makeNextStateCurrent() {
	for (int i=0; i<cols; i++) {
		for (int j=0; j<rows; j++) {
			grid[i][j].currState = grid[i][j].nextState;
		}
	}
}

void ofxGameOfLife::clear() {
	grid = new cell *[cols];
	for (int i=0; i<cols; i++) {
		grid[i] = new cell[rows];
		for (int j=0; j<rows; j++) {
      cell *thisCell = &grid[i][j];
			thisCell->currState = false;
			thisCell->nextState = false;
			thisCell->color = ofColor::black;
		}
	}
}

/**
 * Ensure it is a valid col/row combo (on grid) and
 * that this cell's currState is true
 */
int ofxGameOfLife::currState(int col, int row) {
  return (col >= 0 && row >= 0 &&
          col < cols && row < rows &&
          grid[col][row].currState == true) ? 1 : 0;
}

/**
 * Checks for the number of neighbors that are in an active state
 */
int ofxGameOfLife::getNumActiveNeighbors(int colIndex, int rowIndex) {
  int ret = 0;

  int prevCol = colIndex-1;
  int nextCol = colIndex+1;
  int prevRow = rowIndex-1;
  int nextRow = rowIndex+1;

  ret += currState(prevCol, prevRow);
  ret += currState(prevCol, rowIndex);
  ret += currState(prevCol, nextRow);

  ret += currState(colIndex, prevRow);
  ret += currState(colIndex, nextRow);

  ret += currState(nextCol, prevRow);
  ret += currState(nextCol, rowIndex);
  ret += currState(nextCol, nextRow);

  return ret;
}

int ofxGameOfLife::getCols(){
    return cols;
}

int ofxGameOfLife::getRows(){
    return rows;
}

cell** ofxGameOfLife::getGrid(){
    return grid;
}

cell ofxGameOfLife::getCell(int i, int j){
    return grid[i][j];
}

void ofxGameOfLife::gliderGun(int startPosX, int startPosY) {
  // left box
  grid[startPosX+1][startPosY+5].currState = true;
  grid[startPosX+1][startPosY+6].currState = true;
  grid[startPosX+2][startPosY+5].currState = true;
  grid[startPosX+2][startPosY+6].currState = true;

  // left middle of gun
  grid[startPosX+11][startPosY+5].currState = true;
  grid[startPosX+11][startPosY+6].currState = true;
  grid[startPosX+11][startPosY+7].currState = true;
  grid[startPosX+12][startPosY+4].currState = true;
  grid[startPosX+12][startPosY+8].currState = true;
  grid[startPosX+13][startPosY+3].currState = true;
  grid[startPosX+13][startPosY+9].currState = true;
  grid[startPosX+14][startPosY+3].currState = true;
  grid[startPosX+14][startPosY+9].currState = true;
  grid[startPosX+15][startPosY+6].currState = true;
  grid[startPosX+16][startPosY+4].currState = true;
  grid[startPosX+16][startPosY+8].currState = true;
  grid[startPosX+17][startPosY+5].currState = true;
  grid[startPosX+17][startPosY+6].currState = true;
  grid[startPosX+17][startPosY+7].currState = true;
  grid[startPosX+18][startPosY+6].currState = true;

  // right middle of gun
  grid[startPosX+21][startPosY+3].currState = true;
  grid[startPosX+21][startPosY+4].currState = true;
  grid[startPosX+21][startPosY+5].currState = true;
  grid[startPosX+22][startPosY+3].currState = true;
  grid[startPosX+22][startPosY+4].currState = true;
  grid[startPosX+22][startPosY+5].currState = true;
  grid[startPosX+23][startPosY+2].currState = true;
  grid[startPosX+23][startPosY+6].currState = true;
  grid[startPosX+25][startPosY+1].currState = true;
  grid[startPosX+25][startPosY+2].currState = true;
  grid[startPosX+25][startPosY+6].currState = true;
  grid[startPosX+25][startPosY+7].currState = true;

  // right block
  grid[startPosX+35][startPosY+3].currState = true;
  grid[startPosX+35][startPosY+4].currState = true;
  grid[startPosX+36][startPosY+3].currState = true;
  grid[startPosX+36][startPosY+4].currState = true;
}

void ofxGameOfLife::pufferTrain(int startPosX, int startPosY) {
  grid[startPosX+1][startPosY+2].currState = true;
  grid[startPosX+2][startPosY+1].currState = true;
  grid[startPosX+3][startPosY+1].currState = true;
  grid[startPosX+3][startPosY+5].currState = true;
  grid[startPosX+4][startPosY+1].currState = true;
  grid[startPosX+4][startPosY+2].currState = true;
  grid[startPosX+4][startPosY+3].currState = true;
  grid[startPosX+4][startPosY+4].currState = true;

  grid[startPosX+8][startPosY+5].currState = true;
  grid[startPosX+9][startPosY+3].currState = true;
  grid[startPosX+9][startPosY+4].currState = true;
  grid[startPosX+10][startPosY+3].currState = true;
  grid[startPosX+11][startPosY+3].currState = true;
  grid[startPosX+12][startPosY+4].currState = true;

  grid[startPosX+15][startPosY+2].currState = true;
  grid[startPosX+16][startPosY+1].currState = true;
  grid[startPosX+17][startPosY+1].currState = true;
  grid[startPosX+17][startPosY+5].currState = true;
  grid[startPosX+18][startPosY+1].currState = true;
  grid[startPosX+18][startPosY+2].currState = true;
  grid[startPosX+18][startPosY+3].currState = true;
  grid[startPosX+18][startPosY+4].currState = true;
}

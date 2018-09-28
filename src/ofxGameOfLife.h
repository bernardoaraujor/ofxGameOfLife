#pragma once

#include "ofMain.h"

struct cell {
	bool currState;
	bool nextState;
	int activeNeighbors;
	ofColor color;
};

class ofxGameOfLife {
      public:
        ofxGameOfLife();
        ~ofxGameOfLife();

        void setup(int width, int height, int cellsize);

        void tick();
        void update();
        void clear();
        void pause();

        int getCols();
        int getRows();
        cell** getGrid();
        cell getCell(int i, int j);

        void gliderGun(int startPosX, int startPosY);
        void pufferTrain(int startPosX, int startPosY);

        void keyPressed(int key);
        void mousePressed(int x, int y, int button);

        bool active;

      private:
        cell **grid;
        int rows, cols;
        float cellWidth, cellHeight;
        bool fullScreen, highlight;

        int getNumActiveNeighbors(int colIndex, int rowIndex);
        int currState(int colIndex, int rowIndex);

        void makeNextStateCurrent();
        void goFullScreen();

        const int TICK_INTERVAL = 5;
};

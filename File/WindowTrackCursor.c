//
// Created by Xiaowei Min on 2019-01-29.
//

#include "WindowTrackCursor.h"

windowTrack newCursorTracedWindow(int numRows, int numCols, int rowStar, int colStar){
    windowTrack window;
    window.window = newwin(numRows, numCols, rowStar, colStar);
    window.numRow = numRows;
    window.numCol = numCols;
    return window;
}

void fillWindow(windowTrack* window, char fillChar){
    int row = window->numRow;
    int col = window->numCol;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            mvwaddch(window->window, i, j, fillChar);
        }
    }
    wmove(window->window, 0, 0);
}

//? i created a new window, then i fill the window, but i place the cursor at?

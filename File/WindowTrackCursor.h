//
// Created by Xiaowei Min on 2019-01-29.
//

#ifndef NCURSESCONNECTN_WINDOWTRACKCURSOR_H
#define NCURSESCONNECTN_WINDOWTRACKCURSOR_H

#include <ncurses.h>

typedef struct CursorTrack_Struct{
    int CurRow;
    int CurCol;
    WINDOW* CurWindow;
}CursorTrack;

typedef struct windowTrack_Struct{
    int numRow;
    int numCol;
    WINDOW* window;
}windowTrack;

windowTrack newCursorTracedWindow(int numRows, int numCols, int rowStar, int colStar);
void fillWindow(CursorTrack* window, char fillChar);

#endif //NCURSESCONNECTN_WINDOWTRACKCURSOR_H

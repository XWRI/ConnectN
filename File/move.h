//
// Created by Xiaowei Min on 2019-01-29.
//

#ifndef NCURSESCONNECTN_MOVE_H
#define NCURSESCONNECTN_MOVE_H

#include "board.h"
#include "WindowTrackCursor.h"
#include <stdbool.h>



typedef struct Move_Struct{
    int col;
    int row;
    char PlayerMark;
}Move;

bool isValidMove(Move playMove, Board* playBoard, int numArgsRead, int numArgsNeeded);
Move getValidMove(Board* playBoard, CursorTrack* win, PlayerTurn_type playerTurn);

#endif //NCURSESCONNECTN_MOVE_H

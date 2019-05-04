//
// Created by Xiaowei Min on 2019-01-29.
//

#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "move.h"
#include "ValidInput.h"
#include "WindowTrackCursor.h"


bool isValidMove(Move playMove, Board* playBoard, int numArgsRead, int numArgsNeeded){
    return isValidFormat(numArgsRead, numArgsNeeded) &&
    isInRange(playMove.col, 0, playBoard->numCols - 1) &&
    isInRange(playMove.row, 0, playBoard->numRows - 1) &&
    playBoard->val[playMove.row][playMove.col] == playBoard->defaultChar;
}

Move getValidMove(Board* playBoard, CursorTrack* win, PlayerTurn_type playerTurn){
    Move playMove;
    playMove.PlayerMark = "XO"[playerTurn];

    char input = wgetch(win->CurWindow);
    if(input == "a" || input == "j"){

    }else if(input == "s" || input == "k"){

    }else{

    }
    wrefresh(win->CurWindow);
    return playMove;
}
//
// Created by Xiaowei Min on 2019-01-29.
//

#ifndef NCURSESCONNECTN_WIN_H
#define NCURSESCONNECTN_WIN_H

#include "board.h"
#include <stdbool.h>

bool win(Board playBoard, int numWin);

bool verWin(Board playBoard, int numWin);
bool horWin(Board playBoard, int numWin);
bool DiaWin(Board playBoard, int numWin);

int min(int x, int y);
bool rightDiaWin(Board playBoard, int numWin);
bool leftDiaWin(Board playBoard, int numWin);

bool tie(Board playBoard, int numWin);


#endif //NCURSESCONNECTN_WIN_H

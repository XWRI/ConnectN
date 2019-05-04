//
// Created by Xiaowei Min on 2019-01-29.
//

#ifndef NCURSESCONNECTN_BOARD_H
#define NCURSESCONNECTN_BOARD_H

typedef struct Board_Struct{
    int numRows;
    int numCols;
    char** val;
    char defaultChar;
}Board;

Board makeBoard(int row, int col, char defChar);

typedef enum{player1 = 0, player2 = 1}PlayerTurn_type;

int result();

void print_play_area(int MoveCol, int col, PlayerTurn_type Player);
void print_board(Board playBoard);
void print_announcement(int Final, int col);

void print_playBoard();


#endif //NCURSESCONNECTN_BOARD_H

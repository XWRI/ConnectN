//
// Created by Xiaowei Min on 2019-01-29.
//

#include <stdio.h>
#include <stdlib.h>
#include "board.h"

Board makeBoard(int row, int col, char defChar){
    Board playBoard;

    playBoard.numRows = row;
    playBoard.numCols = col;
    playBoard.defaultChar = defChar;

    playBoard.val = (char**)malloc(sizeof(char*) * playBoard.numRows);
    for (int i = 0; i < playBoard.numRows; ++i) {
        playBoard.val[i] = (char*)malloc(sizeof(char) * playBoard.numCols);
        for (int j = 0; j < playBoard.numCols; ++j) {
            playBoard.val[i][j] = playBoard.defaultChar;
        }
    }
    return playBoard;
}

void print_play_area(int MoveCol, int col, PlayerTurn_type Player){

    if(Player == 0){
        for (int i = 0; i < col; ++i) {
            if(i == MoveCol){
                printf("X");
            }
            else {
                printf(" ");
            }
        }
    }
    if(Player == 1){
        for (int j = 0; j < col; ++j) {
            if(j == MoveCol){
                printf("O");
            }
            else {
                printf(" ");
            }
        }
    }
    printf("\n");
}

void print_board(Board playBoard){

    for (int i = 0; i < playBoard.numCols; ++i) {
        for (int j = 0; j < playBoard.numCols; ++j) {
            printf("%c", playBoard.defaultChar);
        }
        printf("\n");
    }
}

void print_announcement(int Final, int col){

    Final = result();
    if(result == 0){
        printf("Player 1 Won!");
    }
    else if(result == 1){
        printf("Player 2 Won!");
    }
    else if(result == 3){
        printf("Tie Game");
    }
    else{
        for (int i = 0; i < col; ++i) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_playBoard(int MoveCol, int col, PlayerTurn_type Player,Board playBoard, int Final,int Final){
    print_play_area(MoveCol, col, Player);
    print_board(playBoard);
    print_announcement(Final, col);
}
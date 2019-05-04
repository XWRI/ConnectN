//
// Created by Xiaowei Min on 2019-01-29.
//

#include "board.h"
#include "win.h"
#include <stdbool.h>

bool win(Board playBoard, int numWin){
    return verWin(playBoard, numWin) || horWin(playBoard, numWin) || DiaWin(playBoard, numWin);
}

bool verWin(Board playBoard, int numWin){

    int numInACol;
    for (int i = 0; i < playBoard.numCols; ++i) {
        for (int j = 0; j < playBoard.numRows; ++j) {
            numInACol = 0;
            playBoard.defaultChar = 'X';
            if(playBoard.val[j][i] == playBoard.defaultChar ){
                numInACol++;
            }
            else{
                numInACol = 0;
            }
            if(numInACol == numWin){
                return true;
            }
        }
    }
    for (int k = 0; k < playBoard.numCols; ++k) {
        for (int l = 0; l < playBoard.numRows; ++l) {
            numInACol = 0;
            playBoard.defaultChar = 'O';
            if(playBoard.val[l][k] == playBoard.defaultChar ){
                numInACol++;
            }
            else{
                numInACol = 0;
            }
            if(numInACol == numWin){
                return true;
            }
        }
    }
    return false;
}

bool horWin(Board playBoard, int numWin) {

    int numInARow;
    for (int i = 0; i < playBoard.numRows; ++i) {
        for (int j = 0; j < playBoard.numCols; ++j) {
            numInARow = 0;
            playBoard.defaultChar = 'X';
            if (playBoard.val[i][j] == playBoard.defaultChar) {
                numInARow++;
            } else {
                numInARow = 0;
            }
            if (numInARow == numWin) {
                return true;
            }
        }
    }
    for (int k = 0; k < playBoard.numRows; ++k) {
        for (int l = 0; l < playBoard.numCols; ++l) {
            numInARow = 0;
            playBoard.defaultChar = 'O';
            if (playBoard.val[k][l] == playBoard.defaultChar) {
                numInARow++;
            } else {
                numInARow = 0;
            }
            if (numInARow == numWin) {
                return true;
            }
        }
    }
    return false;
}

bool DiaWin(Board playBoard, int numWin){
    return rightDiaWin(playBoard, numWin) || leftDiaWin(playBoard, numWin);
}

int min(int x, int y){
    return y ^ ((x ^ y) & -(x < y));
}

/*int max(int x, int y){
    return x ^ ((x ^ y) & -(x < y));
}*/

bool rightDiaWin(Board playBoard, int numWin) {

    int numInADia;
    int checkMin = min(playBoard.numRows, playBoard.numCols);
    int checkIn;

    for (int i = 0; i < playBoard.numRows - 1; ++i) {
        for (int j = 0; j < playBoard.numCols - 1; ++j) {
            numInADia = 0;
            playBoard.defaultChar = 'X';

        /*    if(playBoard.numRows - i < checkMin){
                checkIn = playBoard.numRows - i;
            }
            else{
                checkIn = checkMin - 1;
            }
            */
            checkIn = min(playBoard.numRows - i, checkMin - 1);

            for (int k = 0; k < checkIn; ++k) {
                if (playBoard.val[i + k][j + k] == playBoard.defaultChar) {
                    numInADia++;
                }
                else{
                    numInADia = 0;
                }
                if(numInADia == numWin){
                    return true;
                }
            }
        }
    }
    for (int g = 0; g < playBoard.numRows - 1; ++g){
        for (int m = 0; m < playBoard.numCols - 1; ++m) {
            numInADia = 0;
            playBoard.defaultChar = 'O';
            checkIn = min(playBoard.numRows - g, checkMin - 1);

            for (int n = 0; n < checkIn; ++n) {
                if (playBoard.val[g + n][m + n] == playBoard.defaultChar) {
                    numInADia++;
                }
                else{
                    numInADia = 0;
                }
                if(numInADia == numWin){
                    return true;
                }
            }
        }
    }
    return false;
}

bool leftDiaWin(Board playBoard, int numWin){

    int numInADia;
    int checkIn;

    for (int i = 0; i < playBoard.numRows - 1; ++i) {
        for (int j = 1; j < playBoard.numCols; ++j) {
            numInADia = 0;
            playBoard.defaultChar = 'X';
            checkIn = min(playBoard.numRows - i, j + 1);

            for (int k = 0; k < checkIn; ++k) {
                if (playBoard.val[i + k][j - k] == playBoard.defaultChar) {
                    numInADia++;
                }
                else{
                    numInADia = 0;
                }
                if(numInADia == numWin){
                    return true;
                }
            }
        }
    }
    for (int g = 0; g < playBoard.numRows - 1; ++g){
        for (int m = 1; m < playBoard.numCols; ++m) {
            numInADia = 0;
            playBoard.defaultChar = 'O';
            checkIn = min(playBoard.numRows - g, m + 1);

            for (int n = 0; n < checkIn; ++n) {
                if (playBoard.val[g + n][m + n] == playBoard.defaultChar) {
                    numInADia++;
                }
                else{
                    numInADia = 0;
                }
                if(numInADia == numWin){
                    return true;
                }
            }
        }
    }
    return false;
}

bool tie(Board playBoard, int numWin){

    if(win(playBoard, numWin)){
        return false;
    }

    for (int i = 0; i < playBoard.numRows; ++i) {
        for (int j = 0; j < playBoard.numCols; ++j) {
            if(playBoard.val[i][j] == playBoard.defaultChar){
                return false;
            }
        }
    }
    return true;
}


int result(){

}
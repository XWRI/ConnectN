#include <stdio.h>
#include <ncurses.h>
#include "board.h"


int main(int argc, char** argv) {

    initscr();
    noecho();
    cbreak();

    int row = sscanf(argv[1], "%d", &row);
    int col = sscanf(argv[2], "%d", &col);
    Board gameBoard = makeBoard(argv[1], argv[2], '*');
    int numNeedWin = sscanf(argv[3], "%d", &numNeedWin);












    return 0;
}
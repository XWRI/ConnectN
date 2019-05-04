//
// Created by Xiaowei Min on 2019-02-13.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <unistd.h>
#include "Input.h"

bool cmd_arg_init(cmd_arg_t *rval, int argc, char **argv) {
    if(argc == 5) {
        rval->num_rows = atoi(argv[1]);
        rval->num_cols = atoi(argv[2]);
        rval->num_pieces_to_win = atoi(argv[3]);
        rval->plog_file = fopen(argv[4], "w");
        return true;
    }
    else if(argc > 5) {
        printf("Too many arguments\n");
        printf("Usage: ./NCursesConnectN.out numRows numCols numPiecesToWin logFileName\n");
    }
    else {
        printf("Usage: ./NCursesConnectN.out numRows numCols numPiecesToWin logFileName\nMissing");
        switch(argc) {
            case 1:
                printf(" numRows numCols numPiecesToWin logFileName\n");
                break;
            case 2:
                printf(" numCols numPiecesToWin logFileName\n");
                break;
            case 3:
                printf(" numPiecesToWin logFileName\n");
                break;
            case 4:
                printf(" logFileName\n");
                break;
        }
        printf("Ending Program\n");
    }
    return false;
}

void cmd_arg_destroy(cmd_arg_t *pcmd_arg) {
    fclose(pcmd_arg->plog_file);
    return;
}
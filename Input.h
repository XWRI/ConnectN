//
// Created by Xiaowei Min on 2019-02-13.
//

#ifndef PROJECT_INPUT_H
#define PROJECT_INPUT_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct cmd_arg_t_ {
    int num_rows;
    int num_cols;
    int num_pieces_to_win;
    FILE *plog_file;
} cmd_arg_t;

bool cmd_arg_init(cmd_arg_t *rval, int argc, char **argv);
void cmd_arg_destroy(cmd_arg_t *pcmd_arg);

#endif //PROJECT_INPUT_H

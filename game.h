//
// Created by Xiaowei Min on 2019-02-13.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "window.h"


typedef struct game_stat_t_ {
    int curse_col;
    int player_now;
    int tot;
    int need_to_win;
    int winner;
    window_t board;
} game_stat_t;

bool game_stat_init(game_stat_t *rval, int num_rows, int num_cols, int need_to_win);
bool game_stat_move(game_stat_t *pgame_stat);
void game_stat_print(game_stat_t *pgame_stat, FILE *fout);
void game_stat_destroy(game_stat_t *pgame_stat);

#endif //PROJECT_GAME_H

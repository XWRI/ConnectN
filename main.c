//
// Created by Xiaowei Min on 2019-02-13.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <memory.h>
#include <ncurses.h>
#include "game.h"
#include "Input.h"


int main(int argc, char **argv) {

    cmd_arg_t param;
    if(!cmd_arg_init(&param, argc, argv)) return 0;

    game_stat_t game_stat;
    game_stat_init(&game_stat, param.num_rows, param.num_cols, param.num_pieces_to_win);

    initscr();
    raw();
    noecho();

    do{
        game_stat_print(&game_stat, param.plog_file);
    } while(!game_stat_move(&game_stat));

    game_stat_print(&game_stat, param.plog_file);

    cmd_arg_destroy(&param);

    endwin();
    return 0;
}
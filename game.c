//
// Created by Xiaowei Min on 2019-02-13.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ncurses.h"
#include "game.h"
#include "window.h"

#define PLAYER_NUMS 2
const char PLAYER_SIGN[] = {'X', 'O'};

bool game_stat_init(game_stat_t *rval, int num_rows, int num_cols, int need_to_win) {
    rval->curse_col = 0;
    rval->player_now = 0;
    rval->winner = 0;
    rval->tot = num_rows * num_cols;
    rval->need_to_win = need_to_win;
    return window_init(&rval->board, num_rows, num_cols);
}

bool game_stat_move(game_stat_t *pgame_stat) {
    char ch = getch();
    if(ch == 'a' || ch == 'j') {
        mvaddch(0, pgame_stat->curse_col, ' ');
        pgame_stat->curse_col = (pgame_stat->curse_col - 1 + pgame_stat->board.num_cols) % pgame_stat->board.num_cols;
        return false;
    }
    if(ch == 's' || ch == 'k') {
        mvaddch(0, pgame_stat->curse_col, ' ');
        pgame_stat->curse_col = (pgame_stat->curse_col + 1) % pgame_stat->board.num_cols;
        return false;
    }
    else if(ch == ' '|| ch == '\n') {
        char *pnow = window_get(&pgame_stat->board, 0, pgame_stat->curse_col);
        if(*pnow != '*') return false;
        int row = 1;
        for(; row < pgame_stat->board.num_rows; ++row) {
            char *pnext = window_get(&pgame_stat->board, row, pgame_stat->curse_col);
            if(*pnext != '*') break;
            pnow = pnext;
        }
        *pnow = PLAYER_SIGN[pgame_stat->player_now];
        if(!(window_count(&pgame_stat->board, --row, pgame_stat->curse_col) == pgame_stat->need_to_win || --pgame_stat->tot == 0)) {
            pgame_stat->player_now = (pgame_stat->player_now + 1) % PLAYER_NUMS;
            return false;
        }
        if(pgame_stat->tot == 0) pgame_stat->winner = -1;
        else pgame_stat->winner = pgame_stat->player_now + 1;
        return true;
    }
    return false;
}

void do_game_stat_print(game_stat_t *pgame_stat);
void do_game_stat_log(game_stat_t *pgame_stat, FILE *fout);
void game_stat_print(game_stat_t *pgame_stat, FILE *fout) {
    do_game_stat_print(pgame_stat);
    do_game_stat_log(pgame_stat, fout);
}

void do_game_stat_print(game_stat_t *pgame_stat) {
    mvaddch(0, pgame_stat->curse_col, PLAYER_SIGN[pgame_stat->player_now]);
    move(1, 0);
    window_print(&pgame_stat->board);
    if(pgame_stat->winner) {
        if(pgame_stat->winner == -1)
            printw("%-15s\n", "Tie Game");
        else printw("Player %d won!  \n", pgame_stat->winner);
    }
    else printw("%15s\n", "");
    addch('\n');
    move(0, pgame_stat->curse_col);
    refresh();
}

void do_game_stat_log(game_stat_t *pgame_stat, FILE *fout) {
    for(int i = 0; i < pgame_stat->board.num_cols; ++i)
        fputc(i == pgame_stat->curse_col ? PLAYER_SIGN[pgame_stat->player_now] : ' ', fout);
    fputc('\n', fout);
    window_log(&pgame_stat->board, fout);
    if(pgame_stat->winner) {
        if(pgame_stat->winner == -1)
            fprintf(fout, "%-15s\n", "Tie Game");
        else fprintf(fout, "Player %d won!  \n", pgame_stat->winner);
    }
    else fprintf(fout, "%15s\n", "");
    fputc('\n', fout);
}


void game_stat_destroy(game_stat_t *pgame_stat) {
    window_destroy(&pgame_stat->board);
}
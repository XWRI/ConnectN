//
// Created by Xiaowei Min on 2019-02-13.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include "ncurses.h"
#include "window.h"

bool window_init(window_t *rval, int num_rows, int num_cols) {
    rval->num_rows = num_rows;
    rval->num_cols = num_cols;
    rval->pval = (char*)malloc(sizeof(char) * num_rows * num_cols);
    if(rval->pval != NULL) memset(rval->pval, '*', num_rows * num_cols);
    return rval->pval != NULL;
}

void window_print(window_t *pwindow) {
    char *tmp = pwindow->pval;
    for(int i = 0; i < pwindow->num_rows; ++i) {
        for(int j = 0; j < pwindow->num_cols; ++j)
            addch(*(tmp++));
        addch('\n');
    }
    refresh();
}

void window_log(window_t *pwindow, FILE *fout) {
    char *tmp = pwindow->pval;
    for(int i = 0; i < pwindow->num_rows; ++i) {
        for(int j = 0; j < pwindow->num_cols; ++j)
            fputc(*(tmp++), fout);
        fputc('\n', fout);
    }
    fflush(fout);
}

char* window_get(window_t *pwindow, int x, int y) {
    if(x < 0 || x >= pwindow->num_rows || y < 0 || y >= pwindow->num_cols) return NULL;
    return pwindow->pval + (x * pwindow->num_cols) + y;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int do_window_count(window_t *pwindow, int x, int y, int dx, int dy) {
    int ans = 0;
    char ch_std = *window_get(pwindow, x, y);
    x += dx;
    y += dy;
    while(x > -1 && x < pwindow->num_rows && y > -1 && y < pwindow->num_cols && (*(window_get(pwindow, x, y)) == ch_std)) {
        ++ans;
        x += dx;
        y += dy;
    }
    return ans;
}

int window_count(window_t *pwindow, int x, int y) {
    const int dx[] = {1, 1, 0, -1};
    const int dy[] = {0, 1, 1, 1};
    int ans = 0;
    for(int i = 0; i < 4; ++i)
        ans = max(ans, 1 + do_window_count(pwindow, x, y, dx[i], dy[i]) + do_window_count(pwindow, x, y, -dx[i], -dy[i]));
    return ans;
}

void window_destroy(window_t *pwindow) {
    free(pwindow->pval);
}
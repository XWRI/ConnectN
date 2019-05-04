//
// Created by Xiaowei Min on 2019-02-13.
//

#ifndef DESKTOP_WINDOW_H
#define DESKTOP_WINDOW_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>


typedef struct window_t_ {
    int num_rows;
    int num_cols;
    char *pval;
} window_t;

bool window_init(window_t *rval, int num_rows, int num_cols);
void window_print(window_t *pwindow);
void window_log(window_t *pwindow, FILE *fout);
char* window_get(window_t *pwindow, int x, int y);
int window_count(window_t *pwindow, int x, int y);
void window_destroy(window_t *pwindow);


#endif //DESKTOP_WINDOW_H

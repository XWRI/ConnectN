//
// Created by Xiaowei Min on 2019-01-29.
//

#ifndef NCURSESCONNECTN_VALIDINPUT_H
#define NCURSESCONNECTN_VALIDINPUT_H

#include <stdbool.h>

bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool isInRange(int val, int LowBound, int UpBound);


#endif //NCURSESCONNECTN_VALIDINPUT_H

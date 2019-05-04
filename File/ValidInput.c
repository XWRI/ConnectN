//
// Created by Xiaowei Min on 2019-01-29.
//

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include "ValidInput.h"

bool isValidFormat(const int numArgsRead, const int numArgsNeed){
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do{
        scanf("%c", &character);
        if(!isspace(character)){
            formatIsGood = false;
        }
    }while(character != '\n');
    return formatIsGood;
}

bool isInRange(int val, int LowBound, int UpBound){
    return val >= LowBound && val <= UpBound;
}

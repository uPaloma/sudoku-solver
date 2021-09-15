#ifndef FINDSOL_H
#define FINDSOL_H
#include<stdio.h>
#include<stdlib.h>
#include "isvalid.h"
#include<string.h>

typedef struct list { // storing "coordintates" of the fixed values
    unsigned int x;
    unsigned int y;
} fixedVal;

enum box_row_column{box, row, column};


void *_init_fixedVal(int **sudoku);

bool isfixedVal (fixedVal *Vallist,int i, int j);

void print_sudoku(int **sudoku);

void *findSol(int **sudoku);

int *numbers_missing(int **sudoku, int i, int j);

void *deductice_nums(int **sudoku);

#endif
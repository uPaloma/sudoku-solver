#ifndef ISVALID_H
#define ISVALID_H
#include<stdbool.h>



bool row_is_Valid(int **sudoku, int i);

bool row_is_Sol(int **sudoku, int i);

bool column_is_Valid(int **sudoku, int i);

bool column_is_Sol(int **sudoku, int i);

bool box_is_Valid(int **sudoku, int i, int j);

bool box_is_Sol(int **sudoku, int i, int j);

bool isValid(int **sudoku);

bool isSol (int **sudoku);

bool isValhere(int **sudoku, int i, int j);

#endif
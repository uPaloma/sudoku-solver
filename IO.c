#include "isvalid.h"
#include "findSol.h"

int main(){
  /*int sudokuez[9][9] = {{8,0,0,  0,0,0,  0,0,0},
                          {0,0,3,  6,0,0,  0,0,0},
                          {0,7,0,  0,9,0,  2,0,0},

                          {0,5,0,  0,0,7,  0,0,0},
                          {0,0,0,  0,4,5,  7,0,0},
                          {0,0,0,  1,0,0,  0,3,0},

                          {0,0,1,  0,0,0,  0,6,8},
                          {0,0,8,  5,0,0,  0,1,0},
                          {0,9,0,  0,0,0,  4,0,0}}; */
                 
 int sudoku[9][9] = {     {0,6,0,  0, 0, 7,  0 ,0 ,0},
                          {1,0,0,  0, 8, 0,  0, 0 ,4},
                          {0,0,0,  9, 1, 0,  0, 0, 0},

                          {0,0,0,  0, 0, 0,  0, 0, 0},
                          {0,0,0,  3, 0, 0,  0, 2, 6},
                          {4,7,0,  0, 0, 6,  8, 0, 0},

                          {6,0,5,  0, 0, 2,  4, 7, 0},
                          {0,0,0,  0, 0, 8,  1, 0, 0},
                          {0,0,9,  0, 0, 0,  0, 3, 0}}; 
   int *sudokuptr[9];

    for (int i = 0; i < 9; ++i) {
         sudokuptr[i] = sudoku[i];
    }
    
fixedVal *val = _init_fixedVal(sudokuptr);

if(isValhere(sudokuptr,0, 5) && isfixedVal(val, 0, 0) && column_is_Valid(sudokuptr, 0)){
printf("Yes\n");
}
else
{
    printf("haha no\n");
}

findSol(sudokuptr);
//print_sudoku(sudokuptr);
//printf("%u, %u\n", val[0].x, val[0].y);
}

#include "isvalid.h"
#include<stdio.h>
#include<stdlib.h>

//Backtracking brute force approach to solve with some minor tweaks for runtime improvement

typedef struct list { // storing "coordintates" of the fixed values
    unsigned short x;
    unsigned short y;
} fixedVal;

 unsigned short numVals = 0; //Index

void *_init_fixedVal(int **sudoku){
    numVals = 0;
    fixedVal *Vallist = malloc(81 * sizeof(fixedVal)); // list of fixed vals
    for(int cnt = 0; cnt < 9; cnt++){
        for(int cnt2 = 0; cnt2 < 9; cnt2++){
            if(sudoku[cnt][cnt2] != 0){
                Vallist[numVals].x = cnt;
                Vallist[numVals].y = cnt2;
                numVals++;
            }
        }
    }
    return Vallist;
}

bool isfixedVal (fixedVal *Vallist,int i, int j){
    bool tf = false;
    for(int cnt = 0;cnt <= numVals; cnt++){
        if(Vallist[cnt].x == i && Vallist[cnt].y == j)
        tf = true;
    }
    return tf;
}

void print_sudoku(int **sudoku){
    for(int cnt = 0; cnt < 9; cnt++){
        for(int cnt2 = 0; cnt2 < 9; cnt2++){
            printf("%d ", sudoku[cnt][cnt2]);
            if(cnt2 == 8)
            printf("\n");
        }
    }
}

void findSol(int **sudoku){
    fixedVal *Vallist = _init_fixedVal(sudoku);
    if(isValid(sudoku)){
    for(int cnt = 0; cnt < 9; cnt++){
        for(int cnt2 = 0; cnt2 < 9; cnt2++){
            if(!isfixedVal(Vallist, cnt, cnt2)){
                sudoku[cnt][cnt2]++;
                while(!isValid(sudoku)){
                    sudoku[cnt][cnt2]++;
                    if(sudoku[cnt][cnt2] == 10){
                        sudoku[cnt][cnt2] = 1;
                        do{
                        if(cnt != 0){
                            cnt--;
                        }
                        else{
                            cnt2--;
                            cnt = 8;
                        }
                        }while(isfixedVal(Vallist, cnt, cnt2));
                        cnt--;
                    }
                }
            }
        }
    }
    print_sudoku(sudoku);
    }
    else{
        printf("This puzzle is not Valid. Please enter a Valid puzzle to solve!");
    }
}





int main(){
    int sudokuez[9][9] = {{5,3,4,  0,7,8,  0,1,2},
                          {6,7,2,  1,9,5,  3,4,8},
                          {0,9,8,  0,4,2,  5,6,7},

                          {0,5,9,  7,6,1,  4,0,3},
                          {4,2,6,  8,0,3,  7,9,1},
                          {7,0,3,  9,2,0,  8,5,6},

                          {9,6,1,  5,3,7,  2,8,4},
                          {2,8,0,  0,1,9,  0,3,5},
                          {3,4,5,  2,8,0,  1,7,9}}; 
                 
   /*int sudoku[9][9] = {   {0,6,0,  0, 0, 7,  0 ,0 ,0},
                          {1,0,0,  0, 8, 0,  0, 0 ,4},
                          {0,0,0,  9, 1, 0,  0, 0, 0},

                          {0,0,0,  0, 0, 0,  0, 0, 0},
                          {0,0,0,  3, 0, 0,  0, 2, 6},
                          {4,7,0,  0, 0, 6,  8, 0, 0},

                          {6,0,5,  0, 0, 2,  4, 7, 0},
                          {0,0,0,  0, 0, 8,  1, 0, 0},
                          {0,0,9,  0, 0, 0,  0, 3, 0}}; */
    int *sudokuptr[9];

    for (int i = 0; i < 9; ++i) {
         sudokuptr[i] = sudokuez[i];
    }
    
fixedVal *val = _init_fixedVal(sudokuptr);

if(isValid(sudokuptr) && isfixedVal(val, 3, 1)){
printf("Yes\n");
}
else
{
    printf("haha no\n");
}

findSol(sudokuptr);
//print_sudoku(sudokuptr);
//printf("%u, %u\n", val[17].x, val[17].y);
}

#include "isvalid.h"
#include<stdio.h>
#include<stdlib.h>

//Backtracking brute force approach to solve with some minor tweaks for runtime improvement

typedef struct list { // storing "coordintates" of the fixed values
    unsigned short x;
    unsigned short y;
} fixedVal;

static unsigned short numVals = 0; //Index

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
        if(Vallist[i].x == i && Vallist[i].y == j)
        tf = true;
    }
    return tf;
}

void print_sudoku(int **sudoku){
    for(int cnt = 0; cnt < 9; cnt++){
        for(int cnt2 = 0; cnt2 < 9; cnt2++){
            printf("%d ", sudoku[cnt2][cnt]);
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
            if(!isfixedVal(Vallist, cnt2, cnt)){
                sudoku[cnt2][cnt]++;
                while(!isValid(sudoku)){
                    sudoku[cnt2][cnt]++;
                    if(sudoku[cnt2][cnt] == 10){
                        sudoku[cnt2][cnt] = 0;
                        do{
                        if(cnt2 != 0){
                            cnt2--;
                        }
                        else{
                            cnt--;
                            cnt2 = 8;
                        }
                        }while(isfixedVal(Vallist, cnt2, cnt));
                        cnt2--;
                        
                        //todo: find way to go back to last changed variable. Therefore one thats not fixed.
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
    
    int sudoku[9][9] = {  {0,6,0,  0, 0, 7,  0 ,0 ,0},
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



if(isValid(sudokuptr)){
printf("Yes\n");
}
else
{
    printf("haha no\n");
}
findSol(sudokuptr);
}
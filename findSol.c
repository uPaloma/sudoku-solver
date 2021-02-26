#include "isvalid.h"
#include "findSol.h"


//Backtracking brute force approach to solve with some minor tweaks for runtime improvement


unsigned int numVals = 0; //Index
long long int x = 0;
int missing_nums[9] = {0};


int *numbers_missing(int **sudoku, int i, int j, enum box_row_column brc,int* missing_nums){
    for(int cnt = 0; cnt < 9; cnt++){
        missing_nums[cnt] = 0;
    }
    int x = i;
    int y = j;
    int *fakesudoku[9];
    int index = 0;
     for (int i = 0; i < 9; ++i) {
         fakesudoku[i] = sudoku[i];
    }
    if(i > 2 && i < 6)
    x = 3;
    if(j > 2 && j < 6)
    y = 3;
    if(i > 5)
    x = 6;
    if(j > 5)
    y = 6;
    switch (brc){
        case box:
        for(int cnt = 1; cnt < 10; cnt++){
            fakesudoku[i][j] = cnt;
            if (box_is_Valid(fakesudoku, x, y)){
              missing_nums[index] = cnt;
              index++;
            }
            }
        return missing_nums;

        case row:
        for(int cnt = 1; cnt < 10; cnt++){
            if(row_is_Valid(fakesudoku, i)){
              missing_nums[index] = cnt;
              index++;
            }
        }
        return missing_nums;

        case column:
        for(int cnt = 1; cnt < 10; cnt++){
            if(column_is_Valid(fakesudoku, i)){
              missing_nums[index] = cnt;
              index++;
            }
        }
        return missing_nums;

        default: return missing_nums;
    }
}

void *deductice_nums(int **sudoku){ 
    fixedVal *Vallist = _init_fixedVal(sudoku);
    int *box_missing, *row_missing, *column_missing;
    bool boxtf = false;
    bool rowtf = false;
    bool columntf = false;
    int index[2] = {0};
    int idx = 0;
    for(int cnt = 1; cnt <= 9; cnt++){
        for(int cnt2 = 0; cnt2 < 9; cnt2++){
            if(!isfixedVal(Vallist, cnt, cnt2)){
                box_missing = numbers_missing(sudoku, cnt, cnt2, box, missing_nums);
                row_missing = numbers_missing(sudoku, cnt, cnt2, row, missing_nums);
                column_missing = numbers_missing(sudoku, cnt, cnt2, column, missing_nums);
                for(int cnt3 = 0; cnt3 < 9; cnt3++){
                    for(int cnt4 = 0; cnt4 < 9; cnt4++){
                    if(cnt3 == box_missing[cnt4])
                    boxtf = true;
                    if(cnt3 == row_missing[cnt4])
                    rowtf = true;
                    if(cnt3 == column_missing[cnt4])
                    columntf = true;
                    if(boxtf && columntf && rowtf){
                        index[idx] = cnt;
                        idx++;
                    }
                    boxtf = false;
                    columntf = false;
                    rowtf = false;
                    if(idx == 2){
                        break;
                    }
                    sudoku[cnt][cnt2] = index[0];
                    Vallist[numVals].x = cnt;
                    Vallist[numVals].y = cnt2;
                    
                }
            }
        }
    }
    }
    print_sudoku(sudoku);
    return sudoku;
}

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
    for(int cnt = 0;cnt < numVals; cnt++){
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
    printf("\n");
}

void *findSol(int **sudoku){
    fixedVal *Vallist = _init_fixedVal(sudoku);
    if(isValid(sudoku)){
    for(int cnt = 0; cnt < 9; cnt++){
        for(int cnt2 = 0; cnt2 < 9; cnt2++){
            if(!isfixedVal(Vallist, cnt, cnt2)){
                x++;
                sudoku[cnt][cnt2]++;
                while(!isValhere(sudoku, cnt, cnt2)){
                    sudoku[cnt][cnt2]++;
                    if(sudoku[cnt][cnt2] > 9){
                        sudoku[cnt][cnt2] = 0;
                        do{
                        if(cnt == 0 && cnt2 == 0){
                            fprintf(stderr,"This Sudoku has no Solution\n");
                            exit(EXIT_FAILURE);
                        }
                        else if(cnt2 != 0){
                            cnt2--;
                        }
                        else{
                            cnt--;
                            cnt2 = 8;
                        }
                        }while(isfixedVal(Vallist, cnt, cnt2));
                        cnt2--;
                    }
                }
            }
        }
    }
    printf("%lld\n\n", x);
    print_sudoku(sudoku);
    }
    else{
        printf("This puzzle is not Valid. Please enter a Valid puzzle to solve!");
    }
    return sudoku;
}


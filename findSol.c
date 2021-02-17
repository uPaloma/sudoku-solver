#include "isvalid.h"
#include "findSol.h"


//Backtracking brute force approach to solve with some minor tweaks for runtime improvement


unsigned int numVals = 0; //Index
long long int x = 0;

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
                printf("%lld\n", x);
                x++;
                //print_sudoku(sudoku);
                sudoku[cnt][cnt2]++;
                while(!isValhere(sudoku, cnt, cnt2)){
                    sudoku[cnt][cnt2]++;
                    //printf("%d\n", sudoku[cnt][cnt2]);
                    if(sudoku[cnt][cnt2] > 9){
                        sudoku[cnt][cnt2] = 0;
                        do{
                        if(cnt2 != 0){
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
    print_sudoku(sudoku);
    }
    else{
        printf("This puzzle is not Valid. Please enter a Valid puzzle to solve!");
    }
    return sudoku;
}






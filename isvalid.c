#include "isvalid.h"



bool has_duplicate_row (int **sudoku, int i){
    bool tf = false;
    for(int cnt = 0; cnt < 9; cnt++){
        for(int cnt2 = 0; cnt2 < 9; cnt2++){
            if( cnt2 != cnt && sudoku [i] [cnt] == sudoku [i] [cnt2] && sudoku [i] [cnt] != 0){
            tf = true;
            }
        }
    }
    return tf;
}


bool row_is_Valid(int **sudoku, int i){
    bool Valid = true;
    for (int cnt = 0; cnt < 9; cnt++){
        if(sudoku [i] [cnt] < 0 || sudoku [i] [cnt] > 9 || has_duplicate_row(sudoku, i) == true){
        Valid = false;
        }
    }
    return Valid;
}


bool row_is_Sol(int **sudoku, int i){
    bool Valid = true;
    for (int cnt = 0; cnt < 9; cnt++){
        if(sudoku [i] [cnt] < 1 || sudoku [i] [cnt] > 9 || has_duplicate_row(sudoku, i) == true)
        Valid = false;
    }
    return Valid;
}


bool has_duplicate_column (int **sudoku, int i){
    bool tf = false;
    for(int cnt = 0; cnt < 9; cnt++){
        for(int cnt2 = 0; cnt2 < 9; cnt2++){
            if( cnt2 != cnt && sudoku [cnt] [i] == sudoku [cnt2] [i] && sudoku [cnt] [i] != 0){
            tf = true;
            }
        }
    }
    return tf;
}

bool column_is_Valid(int **sudoku, int i){
    bool Valid = true;
    for (int cnt = 0; cnt < 9; cnt++){
        if(sudoku [cnt] [i] < 0 || sudoku [cnt] [i] > 9 || has_duplicate_column(sudoku, i) == true){
        Valid = false;
        }
    }
    return Valid;
}

bool column_is_Sol(int **sudoku, int i){
    bool Valid = true;
    for (int cnt = 0; cnt < 9; cnt++){
        if(sudoku [cnt] [i] < 1 || sudoku [cnt] [i] > 9 || has_duplicate_column(sudoku, i) == true)
        Valid = false;
    }
    return Valid;
}

bool has_duplicate_box(int **sudoku, int i, int j){
    bool tf = false;
    for(int cnt = i; cnt < (i + 3); cnt++){
        for(int cnt2 = j; cnt2 < (j + 3); cnt2++){
            for(int cnt3 = i; cnt3 < (i + 3); cnt3++){
                for(int cnt4 = j; cnt4 < (j + 3); cnt4++){
                    if( (cnt != cnt3) && (cnt2 != cnt4) && sudoku [cnt] [cnt2] == sudoku [cnt3] [cnt4] && sudoku [cnt] [cnt2] != 0){
                        tf = true;
                }
            }
        }
    }
}
return tf;
}


bool box_is_Valid(int **sudoku, int i, int j){
    bool Valid = true;
    for(int cnt = i; cnt < (i + 3); cnt++){
        for(int cnt2 = j; cnt2 < (j + 3); cnt2++){
            if(sudoku [cnt] [cnt2] < 0 || sudoku [cnt] [cnt2] > 9 || has_duplicate_box(sudoku, i, j) == true)
            Valid = false;
        }
    }
    return Valid;
}



bool box_is_Sol(int **sudoku, int i, int j){
    bool Valid = true;
      for(int cnt = i; cnt < (i + 3); cnt++){
        for(int cnt2 = j; cnt2 < (j + 3); cnt2++){
            if(sudoku [cnt] [cnt2] < 1 || sudoku [cnt] [cnt2] > 9 || has_duplicate_box(sudoku, i, j) == true)
            Valid = false;
        }
      }
    return Valid;
}

bool isValid(int **sudoku){
    bool Valid = true;
    for(int cnt = 0; cnt < 9; cnt++){
            if (!row_is_Valid(sudoku, cnt) || !column_is_Valid(sudoku, cnt))
            Valid = false;
    }
    for(int cnt = 0; cnt < 9; cnt += 3){
        for(int cnt2 = 0; cnt2 < 9; cnt2 += 3){
        if( !box_is_Valid(sudoku, cnt, cnt2)){
        Valid = false;
        }
    }
    }
    return Valid;
}

bool isSol (int **sudoku){
    bool Valid = true;
    for(int cnt = 0; cnt < 9; cnt++){
            if (!row_is_Sol(sudoku, cnt) || !column_is_Sol(sudoku, cnt))
            Valid = false;
    }
        for(int cnt = 0; cnt < 9; cnt += 3){
        for(int cnt2 = 0; cnt2 < 9; cnt2 += 3){
        if( !box_is_Sol(sudoku, cnt, cnt2)){
        Valid = false;
        }
    }
    }
    return Valid;
}


 bool isValhere(int **sudoku, int i, int j){
    bool Valid = false;
    int x = 0;
    int y = 0;
    if(i > 2 && i < 6)
    x = 3;
    if(j > 2 && j < 6)
    y = 3;
    if(i > 5)
    x = 6;
    if(j > 5)
    y = 6;

    if(row_is_Valid(sudoku, i) && column_is_Valid(sudoku, j) && box_is_Valid(sudoku, x, y))
    Valid = true;

    return Valid;

}

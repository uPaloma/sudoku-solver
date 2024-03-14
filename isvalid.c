#include "isvalid.h"

bool has_duplicate_row(int **sudoku, int i) {
  bool tf = false;
  for (int cnt = 0; cnt < 9; cnt++) {
    for (int cnt2 = 0; cnt2 < 9; cnt2++) {
      if (cnt2 != cnt && sudoku[i][cnt] == sudoku[i][cnt2] &&
          sudoku[i][cnt] != 0) {
        tf = true;
      }
    }
  }
  return tf;
}

bool row_is_Valid(int **sudoku, int i) {
  bool Valid = true;
  for (int cnt = 0; cnt < 9; cnt++) {
    if (sudoku[i][cnt] < 0 || sudoku[i][cnt] > 9 ||
        has_duplicate_row(sudoku, i) == true) {
      Valid = false;
    }
  }
  return Valid;
}



bool has_duplicate_column(int **sudoku, int i) {
  bool tf = false;
  for (int cnt = 0; cnt < 9; cnt++) {
    for (int cnt2 = 0; cnt2 < 9; cnt2++) {
      if (cnt2 != cnt && sudoku[cnt][i] == sudoku[cnt2][i] &&
          sudoku[cnt][i] != 0) {
        tf = true;
      }
    }
  }
  return tf;
}

bool column_is_Valid(int **sudoku, int i) {
  bool Valid = true;
  for (int cnt = 0; cnt < 9; cnt++) {
    if (sudoku[cnt][i] < 0 || sudoku[cnt][i] > 9 ||
        has_duplicate_column(sudoku, i) == true) {
      Valid = false;
    }
  }
  return Valid;
}


bool has_duplicate_box(int **sudoku, int i, int j) {
  bool tf = false;
  for (int cnt = i; cnt < (i + 3); cnt++) {
    for (int cnt2 = j; cnt2 < (j + 3); cnt2++) {
      for (int cnt3 = i; cnt3 < (i + 3); cnt3++) {
        for (int cnt4 = j; cnt4 < (j + 3); cnt4++) {
          if ((cnt != cnt3) && (cnt2 != cnt4) &&
              sudoku[cnt][cnt2] == sudoku[cnt3][cnt4] &&
              sudoku[cnt][cnt2] != 0) {
            tf = true;
          }
        }
      }
    }
  }
  return tf;
}

bool box_is_Valid(int **sudoku, int i, int j) {
  bool Valid = true;
  for (int cnt = i; cnt < (i + 3); cnt++) {
    for (int cnt2 = j; cnt2 < (j + 3); cnt2++) {
      if (sudoku[cnt][cnt2] < 0 || sudoku[cnt][cnt2] > 9 ||
          has_duplicate_box(sudoku, i, j) == true)
        Valid = false;
    }
  }
  return Valid;
}



bool isValid(int **sudoku) {
  bool Valid = true;
  for (int cnt = 0; cnt < 9; cnt++) {
    if (!row_is_Valid(sudoku, cnt) || !column_is_Valid(sudoku, cnt))
      Valid = false;
  }
  for (int cnt = 0; cnt < 9; cnt += 3) {
    for (int cnt2 = 0; cnt2 < 9; cnt2 += 3) {
      if (!box_is_Valid(sudoku, cnt, cnt2)) {
        Valid = false;
      }
    }
  }
  if(!box_is_Valid(sudoku,1,1) || !box_is_Valid(sudoku,1,5) || !box_is_Valid(sudoku,5,1) || !box_is_Valid(sudoku,5,5)){
    Valid = false;
  }
  return Valid;
}



bool isValhere(int **sudoku, int i, int j) {
  bool Valid = false;
  // since we have negative numbers in the backtracking loop this needs to return true when it receives negative input
  if(j < 0){
    return true;
  }
  int hyperX = 1;
  int hyperY = 1;
  int x = 0;
  int y = 0;
  if (i > 2 && i < 6)
    x = 3;
  if (j > 2 && j < 6)
    y = 3;
  if (i > 5)
    x = 6;
  if (j > 5)
    y = 6;
  if(j > 0 && j < 4){
    hyperY = 1;
    if(i > 0 && i < 4){
      hyperX = 1;
    }
    else if(i > 4 && i < 8){
      hyperX = 5;
    }
    
  }
  if(j > 4 && j < 8){
    hyperY = 5;
    if(i > 0 && i < 4){
      hyperX = 1;
    }
    else if(i > 4 && i < 8){
      hyperX = 5;
    }
  }
  if (row_is_Valid(sudoku, i) && column_is_Valid(sudoku, j) &&
      box_is_Valid(sudoku, x, y) && box_is_Valid(sudoku,hyperX,hyperY))
    Valid = true;

  return Valid;
}

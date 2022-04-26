#include "findSol.h"
#include "isvalid.h"

// Backtracking brute force approach to solve with some minor tweaks for runtime
// improvement Runtime improved by finding numbers deductively Possibly more
// tweaks added in future by statistical analysis of sudoku.

unsigned int numVals = 0; // Index

int *numbers_missing(int **sudoku, int i, int j) {
  int *missing_nums = calloc(9, 9 * sizeof(int));
  int fakesudoku[9][9];
  int *fakesudokuptr[9];
  int index = 0;
  memcpy(fakesudoku, sudoku,
         9 * 9 * sizeof(int)); // copying into seperate "fakesudoku" because of
  memcpy(fakesudokuptr, fakesudoku, 9 * 9 * sizeof(int));

  for (int cnt = 1; cnt < 10; cnt++) {
    fakesudokuptr[i][j] = cnt;
    if (isValhere(fakesudokuptr, i,
                  j)) { // trial and error if numbers from 1-9 are valid at this
                        // point and adds them to the index missing_nums
      missing_nums[index] = cnt;
      index++;
    }
  }
  fakesudokuptr[i][j] =
      0; // reassigns value 0(empty space in this case) to the fakesudoku
  return missing_nums;
}

void *deductice_nums(int **sudoku) {
  fixedVal *Vallist = _init_fixedVal(
      sudoku); // list of values that are != 0 so they shouldnt be changed
  int *nums_missing = malloc(9 * sizeof(int));
  int missing_num_cnt = 0;
  bool nums_added =
      true; // boolean for repetition algorythm; should go through the entire
            // sudoku until it cant find any numbers anymore
  int num_added_cnt = 0; // for testing purposes
  while (nums_added) {
    nums_added = false;
    for (int cnt = 0; cnt < 9; cnt++) { // for loop to go through sudoku (9*9)
      for (int cnt2 = 0; cnt2 < 9; cnt2++) {
        if (!isfixedVal(
                Vallist, cnt,
                cnt2)) { // shouldnt change anything if the value is != 0
          nums_missing =
              numbers_missing(sudoku, cnt, cnt2); // init missing numbers list
          for (int cnt3 = 0; cnt3 < 9; cnt3++) {
            if (nums_missing[cnt3] != 0) { // if only one number is != 0 it will
                                           // be added into the sudoku
              missing_num_cnt++;
            }
          }
        }
        if (missing_num_cnt == 1) {
          sudoku[cnt][cnt2] = nums_missing[0];
          Vallist[numVals].x = cnt; // updating fixedValue list
          Vallist[numVals].y = cnt2;
          numVals++;
          missing_num_cnt = 0;
          nums_added = true;
          num_added_cnt++;
        } else {
          missing_num_cnt = 0;
        }
      }
    }
  }
  printf("deductive numbers found: %d\n", num_added_cnt);
  print_sudoku(sudoku);
  return sudoku;
}

void *_init_fixedVal(int **sudoku) {
  numVals = 0;
  fixedVal *Vallist = malloc(81 * sizeof(fixedVal)); // list of fixed vals
  for (int cnt = 0; cnt < 9; cnt++) {
    for (int cnt2 = 0; cnt2 < 9; cnt2++) {
      if (sudoku[cnt][cnt2] != 0) {
        Vallist[numVals].x = cnt;
        Vallist[numVals].y = cnt2;
        numVals++;
      }
    }
  }
  return Vallist;
}

bool isfixedVal(fixedVal *Vallist, int i, int j) {
  bool tf = false;
  for (int cnt = 0; cnt < numVals; cnt++) {
    if (Vallist[cnt].x == i && Vallist[cnt].y == j)
      tf = true;
  }
  return tf;
}

void print_sudoku(int **sudoku) {
  for (int cnt = 0; cnt < 9; cnt++) {
    for (int cnt2 = 0; cnt2 < 9; cnt2++) {
      printf("%d ", sudoku[cnt][cnt2]);
      if (cnt2 == 8)
        printf("\n");
    }
  }
  printf("\n");
}

void *backtrackSol(int **sudoku) {
  fixedVal *Vallist = _init_fixedVal(sudoku);
  if (isValid(sudoku)) { // to not attempt to solve insolvable sudokus
    for (int cnt = 0; cnt < 9; cnt++) { // for loop to go through sudoku (9*9)
      for (int cnt2 = 0; cnt2 < 9; cnt2++) {
        if (!isfixedVal(Vallist, cnt, cnt2)) {
          sudoku[cnt][cnt2]++;
          //If increment doesnt turn out to be a valid number we increment further in the while loop
          while (!isValhere(sudoku, cnt, cnt2)) {
            sudoku[cnt][cnt2]++;
            if (sudoku[cnt][cnt2] > 9) {
              sudoku[cnt][cnt2] = 0;
              //if no number was valid in this spot we go back to the last not fixed val
              do {
                if (cnt == 0 && cnt2 == 0) {
                  fprintf(stderr, "This Sudoku has no Solution\n");
                  return NULL;
                } else if (cnt2 != 0) {
                  cnt2--;
                } else if (cnt2 == 0) {
                  cnt--;
                  cnt2 = 8;
                }
              } while (isfixedVal(Vallist, cnt, cnt2));
              cnt2--;// to prevent infinite loop
            }
          }
        }
      }
    }
    print_sudoku(sudoku);
  } else {
    printf("This puzzle is not Valid. Please enter a Valid puzzle to solve!");
  }
  free(Vallist);
  return sudoku;
}

void *findSol(int **sudoku) {
  return backtrackSol(deductice_nums(
      sudoku)); // uses deductive nums first since every number found quickly
                // drastically improves the backtracking runtime
}
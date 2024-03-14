#include "findSol.h"
#include "isvalid.h"
#include <ctype.h>

void exit_program(){
  printf("Ending program...\n");
  exit(EXIT_SUCCESS);
}

void print_to_txt(int **sudoku, FILE *fp){ //prinnt the solved sudoku to the .txt file
  for (int cnt = 0; cnt < 9; cnt++) {
    for (int cnt2 = 0; cnt2 < 9; cnt2++) {
      if(cnt2 == 3 || cnt2 == 6 ){
        fprintf(fp,"| ");
      }
      fprintf(fp,"%d ", sudoku[cnt][cnt2]);
      if (cnt2 == 8)
        fprintf(fp,"\n");
      if((cnt == 2 && cnt2 == 8) || (cnt == 5 && cnt2 == 8)){
        fprintf(fp,"---------------------\n");
      }
    }
  }
  fprintf(fp,"\n");

}

void init_sudoku_template(FILE *fp){
  fp = fopen("sudoku.txt", "w"); //setup template file for sudoku
  fputs("0 0 0 | 0 0 0 | 0 0 0\n0 0 0 | 0 0 0 | 0 0 0\n0 0 0 | 0 0 0 | 0 0 "
        "0\n---------------------\n0 0 0 | 0 0 0 | 0 0 0\n0 0 0 | 0 0 0 | 0 0 "
        "0\n0 0 0 | 0 0 0 | 0 0 0\n---------------------\n0 0 0 | 0 0 0 | 0 0 "
        "0\n0 0 0 | 0 0 0 | 0 0 0\n0 0 0 | 0 0 0 | 0 0 0\n",
        fp);
  fclose(fp);

}

void read_sudoku_txt(int** sudoku, FILE *fp){
  int counter = 0;
  char buffer[1000];

  fp = fopen("sudoku.txt", "r+"); //initialization of the read file and sudoku array
    while (fgets(buffer, 1000, fp) != NULL) {
      if (*buffer == '-') {
        continue;
      }
      int counter2 = 0;
      for (int cnt = 0; cnt < 300; cnt++) {
        if (isdigit(buffer[cnt])) {
          sudoku[counter][counter2] = buffer[cnt] - '0';
          counter2++;
          if (counter2 == 9) {
            break;
          }
        }
      }
      counter++;
      if(counter == 9){
        break;
      }
    }

    printf("\n\n");

    fclose(fp);
}

void interface(int** sudoku, FILE *fp){
  char input;
  printf("Please press Y/y and enter after you've entered the sudoku and N/n to "
         "discard and end the programm. IMPORTANT: Dont forget to save the sudoku.txt file after you've entered the sudoku. You might have to reopen the *.txt file to see the solved sudoku there.\n");
  scanf(" %c", &input);
  if (input == 'Y' || input == 'y') {
    read_sudoku_txt(sudoku, fp);
    findSol(sudoku);
    fp = fopen("sudoku.txt", "w");
    print_to_txt(sudoku,fp);
    fclose(fp);
    printf("\n");
}else if(input == 'N' || input == 'n'){
    exit_program();
    }
     else{
        printf("Couldn't read input...Please make sure to only write one character");
        interface(sudoku,fp);
     }
  }



void repeat_until_closed(int** sudoku, FILE *fp){
    char input;
  printf("Do you want to solve another hyper sudoku? Press Y/y to continue and enter N/n  to end the program. NOTE: You might wanna reopen the sudoku.txt file in order to have the original template\n");
  scanf(" %c", &input);
     

  if (input == 'Y' || input == 'y'){
    init_sudoku_template(fp);
    interface(sudoku,fp);
    repeat_until_closed(sudoku,fp);
    }
    else if(input == 'N' || input == 'n'){
    exit_program();
    }
    else{
        printf("Couldn't read input...Please make sure to only write one character");
        repeat_until_closed(sudoku,fp);
    }
         

}


int main() {
  FILE *fp = NULL;
  // first messages and interface
  printf("sudoku-solver v.1.1\nMade by Benedict Volz\nWelcome to the "
         "hyper-sudoku-solver! Please enter the hyper sudoku in the given Text file or "
         "generate a new one.It will appear in whichever directory you have the program saved.\nImportant Note: Please only change the number "
         "Values in the sudoku.txt file as it can lead to bugs."
         "0s are blank spaces in the sudoku so change it to the appropriate values.\nHave fun!\n");
  
  // file opening and IO stream
  int sudoku[9][9] = {{0}}; //initialize sudoku array

 

  int *sudokuptr[9];

  for (int i = 0; i < 9; ++i) { //init pointer to sudoku
    sudokuptr[i] = sudoku[i];
  }

  init_sudoku_template(fp);
  interface(sudokuptr,fp);
  repeat_until_closed(sudokuptr,fp);

  return EXIT_FAILURE;



 
  
}
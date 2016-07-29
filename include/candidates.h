#ifndef CANDIDATES_H
#define CANDIDATES_H
//--------------------------------------------
//Global VAR----------------------------------
//--------------------------------------------
extern int main_table[9][9];
extern int check_table[9][9];
extern int temp_table[9][9][9];
extern int total;

//-------------------------------------------
//function-----------------------------------
//-------------------------------------------
void candidates(int row, int column, int num);
void check_sudoku();
int singles_candidature();
int hidden_singles_candidature();
int single_sector_candidates();
int naked_pairs();

#endif

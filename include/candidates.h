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
int singles_candidature();

#endif

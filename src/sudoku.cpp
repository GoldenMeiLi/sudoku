#include<iostream>
#include<fstream>
#include"candidates.h"
using std::cout;
using std::endl;
using std::fstream;
using std::ios;
//using namespace std;
//----------------------------------------------------------
//Golbal VAR------------------------------------------------
//----------------------------------------------------------
int main_table[9][9];
int check_table[9][9];
int temp_table[9][9][9];
int total;


//---------------------------------------------------------
//function-------------------------------------------------
//---------------------------------------------------------
void reset_table();
void print_table();
void print_check();



int main()
{
fstream test_file("sudoku.txt",ios::in);
//test_file.open("sudoku.txt",ios::in);
//char test_list[82] = "600010403003605200010070000300040908040908020908020007000030050004106700702050006";
char test_list[82];
test_file.getline(test_list,sizeof(test_list));
test_file.close();
cout<<test_file.eof();
int tmp;
int i,j,k;

reset_table();
//---------------------------------------------
//set question---------------------------------
//---------------------------------------------
    k = 0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            tmp = test_list[k] - 48;
            if(tmp > 0)
            {
                candidates(i,j,tmp);
            } 
            k++;
        }
    }
print_table();
cout<<endl;
//---------------------------------------------
//work------------------------------------
//---------------------------------------------
    while(total > 0)
    {
        if(singles_candidature())
        {
            continue;
        }
        if(hidden_singles_candidature())
        {
            continue;
        }
        if(single_sector_candidates())
        {
            continue;
        }
        cout<<"sorry it can't find the answer"<<endl;
        break;
    }
//cout<<endl;

print_table();
cout<<endl;
check_sudoku();
return 0;
}








//------------------------------------------------------
//function----------------------------------------------
//------------------------------------------------------
void reset_table()
{

    int i,j,k;

    total = 81;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            main_table[i][j] = 0;
            check_table[i][j] = 9;
            for(k=0;k<9;k++)
            {
                temp_table[i][j][k] = 1;
            } 
        }
    }

}

void print_table()
{

    int i,j;

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<main_table[i][j];
        }
        cout<<endl;
    }

}

void print_check()
{

    int i,j;

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<check_table[i][j];
        }
        cout<<endl;
    }

}

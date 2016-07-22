#include<iostream>
#include"candidates.h"
using std::cout;
using std::endl;
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
char test_list[82] = "000000500400018090018002003009206350040000070051809200100900630020630007005000000";
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
        singles_candidature();
    }


print_table();
cout<<endl;

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

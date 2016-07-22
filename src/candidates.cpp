#include<iostream>
#include"candidates.h"

using std::cout;
using std::endl;

void candidates(int row, int column, int num)
{
    int i,j;

    //---------------------------------------------------------
    //set main , check and temp--------------------------------
    //---------------------------------------------------------
        main_table[row][column] = num;
        check_table[row][column] = 0;
        for(i=0;i<9;i++)
        {
            temp_table[row][column][i] = 0;
        }
    //---------------------------------------------------------
    //set other check and temp--------------------------
    //---------------------------------------------------------
        //----------------------------------------------------
        //set row---------------------------------------------
        //----------------------------------------------------
        for(i=0;i<9;i++)
        {
            if(check_table[row][i] > 1 && temp_table[row][i][num-1] == 1)
            {
                check_table[row][i] -= 1;
                temp_table[row][i][num-1] = 0;
            }
        }
        //---------------------------------------------------
        //set column-----------------------------------------
        //---------------------------------------------------
        for(i=0;i<9;i++)
        {
            if(check_table[i][column] > 1 && temp_table[i][column][num-1] == 1)
            {
                check_table[i][column] -= 1;
                temp_table[i][column][num-1] = 0; 
            }
        }
        //--------------------------------------------------
        //set block-----------------------------------------
        //--------------------------------------------------
        int k,l;
        k = row / 3 * 3;
        l = column / 3 * 3;
        for(i=k;i<k+3;i++)
        {
            for(j=l;j<l+3;j++)
            {
                if(check_table[i][j] > 1 && temp_table[i][j][num-1] == 1)
                {
                    check_table[i][j] -= 1;
                    temp_table[i][j][num-1] = 0;
                }
            }
        }

    total--;
}

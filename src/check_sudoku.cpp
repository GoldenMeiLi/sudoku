#include<iostream>
#include"candidates.h"

using std::cout;
using std::endl;

void check_sudoku()
{

    int i,j,k,m,n;
    int tmp,error;
    int check_list[9],check;
    error = 0;
    //-------------------------------------------------------------
    //check row----------------------------------------------------
    //-------------------------------------------------------------
    for(i=0;i<9;i++)
    {
        for(k=0;k<9;k++)
        {
            check_list[k] = 0;
        }
        
        for(j=0;j<9;j++)
        {
            tmp = main_table[i][j];
            if(check_list[tmp-1] == 0)
            {
                check_list[tmp-1] = 1;
            }
            else
            {
                error++;
                break;
            } 
        }
        if(error > 0)
            break;
    }
    //------------------------------------------------------------
    //check column------------------------------------------------
    //------------------------------------------------------------
    for(j=0;j<9;j++)
    {
        for(k=0;k<9;k++)
        {
            check_list[k] = 0;
        }
        
        for(i=0;i<9;i++)
        {
            tmp = main_table[i][j];
            if(check_list[tmp-1] == 0)
            {
                check_list[tmp-1] == 1;
            }
            else
            {
                error++;
                break;
            }
        }
        if(error > 0)
            break;
     }
    //----------------------------------------------------------
    //check block-----------------------------------------------
    //----------------------------------------------------------
    for(i=0;i<9;i=i+3)
    {
        for(j=0;j<9;j=j+3)
        {
            tmp = 0;
            for(m=i;m<i+3;m++)
            {
                for(n=j;n<j+3;n++)
                {
                    tmp = tmp + main_table[m][n];
                }
            }

            if(tmp != 45)
                error++; 
        }
             
    }
    
    if(error == 0)
        cout<<"OK"<<endl;
    else
        cout<<"error"<<endl;
}

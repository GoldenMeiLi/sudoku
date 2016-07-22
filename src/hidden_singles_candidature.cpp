#include<iostream>
#include"candidates.h"


int hidden_singles_candidature()
{

    int i,j,k,m,n,o,p;
    int sum;

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(check_table[i][j] > 1)
            {
                for(k=0;k<9;k++)
                {
                    if(temp_table[i][j][k] == 1)
                    {
                        //-----------------------------------
                        //check row--------------------------
                        //-----------------------------------
                        sum = 0;
                        for(m=0;m<9;m++)
                        {
                            if(temp_table[i][m][k] == 1)
                            {
                                sum++;
                            }             
                        }
                        if(sum == 1)
                        {
                            candidates(i,j,k+1);
                            break;
                        }
                        //-----------------------------------
                        //check column-----------------------
                        //-----------------------------------
                        sum = 0;
                        for(m=0;m<9;m++)
                        {
                            if(temp_table[m][j][k] ==1)
                            {
                                sum++;
                            }
                        }
                        if(sum == 1)
                        {
                            candidates(i,j,k+1);
                            break;
                        }
                        //-----------------------------------
                        //check block------------------------
                        //-----------------------------------
                        o = i / 3 * 3;
                        p = j / 3 * 3;
                        sum = 0;
                        for(m=o;m<o+3;m++)
                        {
                            for(n=p;n<p+3;n++)
                            {
                                if(temp_table[m][n][k] == 1)
                                {
                                    sum++;
                                }
                            }
                        }              
                        if(sum == 1)
                        {
                            candidates(i,j,k+1);
                            break;
                        }
                    } 
                }
            }
        }
    }


return 1;
}

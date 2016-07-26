#include<iostream>
#include"candidates.h"
using std::cout;
using std::endl;
void row_del_block(int row, int column, int num);
void column_del_block(int row, int column, int num);
void block_del_row(int row, int column, int num);
void block_del_column(int row, int column, int num);

int single_sector_candidates()
{
    int i,j,k,m,n,o,p;
    int r_sum,c_sum,br_sum,bc_sum,check(0);

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
                        //----------------------------------------
                        //check row-------------------------------
                        //----------------------------------------
                        r_sum = 0;
                        for(m=0;m<9;m++)
                        {
                            if(temp_table[i][m][k] == 1 && (m/3*3 != j/3*3) )
                            {
                                r_sum++;
                            }
                            /*if(sum == 0)
                            {
                                //del_block(); 
                                cout<<"dr ";
                            }*/
                        } 
                        //----------------------------------------
                        //check column----------------------------
                        //----------------------------------------
                        c_sum = 0;
                        for(m=0;m<9;m++)
                        {
                            if(temp_table[m][j][k] == 1 && (m/3*3 != i/3*3) )
                            {
                                c_sum++;
                            }
                            /*if(sum == 0)
                            {
                                //del_block();
                                cout<<"dc ";
                            }*/
                        }
                        //----------------------------------------
                        //check block-----------------------------
                        //----------------------------------------
                        br_sum = 0;
                        bc_sum = 0;
                        o=i/3*3;
                        p=j/3*3;
                        for(m=o;m<o+3;m++)
                        {
                            for(n=p;n<p+3;n++)
                            {
                                if(temp_table[m][n][k] == 1 && m != i )
                                {
                                    br_sum++;
                                }
                                if(temp_table[m][n][k] == 1 && n != j )
                                {
                                    bc_sum++;
                                }
                                /*if(sum == 0)
                                {
                                    //del_row_column();
                                    cout<<"drc ";
                                }*/
                            }
                        } 
                        if(r_sum == 0 && br_sum != 0)
                        {
                            //cout<<"("<<i<<","<<j<<","<<k<<")"<<1;
                            row_del_block(i,j,k); 
                            check++;
                        }
                        if(c_sum == 0 && bc_sum != 0)
                        {
                            //cout<<"("<<i<<","<<j<<","<<k<<")"<<2;
                            column_del_block(i,j,k); 
                            check++;
                        }
                        if(r_sum != 0 && br_sum == 0)
                        {
                            //cout<<"("<<i<<","<<j<<","<<k<<")"<<3;
                            block_del_row(i,j,k); 
                            check++;
                        }
                        if(c_sum != 0 && bc_sum ==0)
                        {
                            //cout<<"("<<i<<","<<j<<","<<k<<")"<<4;
                            block_del_column(i,j,k); 
                            check++;
                        }
                    }
                } 
            }
        } 
    }


return check;
}






void row_del_block(int row, int column, int num)
{
    int i,j,o,p;
    o=row/3*3;
    p=column/3*3;
    
    for(i=o;i<o+3;i++)
    {
        for(j=p;j<p+3;j++)
        {
            if(i!=row && temp_table[i][j][num] == 1)
            {
                temp_table[i][j][num] = 0;
                check_table[i][j] -= 1;
            }
        }
    }
}

void column_del_block(int row, int column, int num)
{
    int i,j,o,p;
    o=row/3*3;
    p=column/3*3;
    
    for(i=o;i<o+3;i++)
    {
        for(j=p;j<p+3;j++)
        {
            if(j!=column && temp_table[i][j][num] == 1)
            {
                temp_table[i][j][num] = 0;
                check_table[i][j] -= 1;
            }
        }
    }
}

void block_del_row(int row, int column, int num)
{
   int i,p;
   p=column/3*3;
    
   for(i=0;i<9;i++)
   {
       if( (i<p || i>=p+3) && temp_table[row][i][num] == 1)
       {
           temp_table[row][i][num] = 0;
           check_table[row][i] -= 1;
       }
   }
}

void block_del_column(int row, int column, int num)
{
    int i,o;
    o=row/3*3;

    for(i=0;i<9;i++)
    {
        if( (i<o || i>=o+3) && temp_table[i][column][num] == 1)
        {
            temp_table[i][column][num] = 0;
            check_table[i][column] -= 1;
        }
    }
}

#include<iostream>
#include"candidates.h"
using std::cout;

int naked_pairs()
{
    int check(0);
    int i,j,k,m,n,q,r;
    int total,qualify,match;
    //--------------------------------------------------------
    //check row-----------------------------------------------
    //--------------------------------------------------------
    for(i=0;i<9;i++)
    {
        total = 0;
        qualify = 0;
        //---------------------------------------
        //check if meet the requirements---------
        //---------------------------------------
        for(j=0;j<9;j++)
        {
            if(check_table[i][j] > 1)
                total++;
            if(check_table[i][j] == 2)
                qualify++;
        }
        //--------------------------------------
        //
        //--------------------------------------
        if(total > 2 && qualify >= 2)
        {
            for(j=0;j<9;j++)
            {
                if(check_table[i][j] == 2)
                {
                    qualify = 0;
                    for(n=j;n<9;n++)
                    {
                        if(check_table[i][n] == 2)
                            qualify++; 
                    }
                    if(qualify >= 2)
                    {
                        for(n=j+1;n<9;n++)
                        {
                            match = 0;
                            for(k=0;k<9;k++)
                            {
                                if(temp_table[i][j][k] == temp_table[i][n][k])
                                    match++;
                            } 
                            if(match == 9)
                            {
                                for(r=0;r<9;r++)
                                {
                                    if( r != j && r != n )
                                    {
                                        for(k=0;k<9;k++)
                                        {
                                            if(temp_table[i][j][k] == 1 && temp_table[i][r][k] == 1)
                                            {
                                                check_table[i][r] -= 1;
                                                temp_table[i][r][k] = 0;
                                                check++;
                                                cout<<"("<<i<<","<<r<<")r"<<k+1;
                                            }
                                        }
                                    }
                                } 
                                break;
                            }
                        }
                    }
                }
                if(qualify < 2)
                    break;
            } 
        }
    }
    //--------------------------------------------------------------------------------------
    //check column--------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------
    for(j=0;j<9;j++)
    {
        total = 0;
        qualify = 0;
        for(i=0;i<9;i++)
        {
            if(check_table[i][j] > 1)
                total++;
            if(check_table[i][j] == 2)
                qualify++;
        }
        if(total > 2 && qualify >=2)
        {
            for(i=0;i<9;i++)
            {
                if(check_table[i][j] == 2)
                {
                   qualify = 0;
                   for(m=i;m<9;m++)
                   {
                       if(check_table[m][j] == 2)
                           qualify++;
                   }
                   if(qualify >= 2)
                   {
                       match=0;
                       for(m=i+1;m<9;m++)
                       {
                           match=0;
                           for(k=0;k<9;k++)
                           {
                               if(temp_table[i][j][k] == temp_table[m][j][k])
                                   match++;
                           }
                           if(match==9)
                           {
                               for(q=0;q<9;q++)
                               {
                                   if(q != i && q != m)
                                   {
                                       for(k=0;k<9;k++)
                                       {
                                           if(temp_table[i][j][k] == 1 && temp_table[q][j][k] == 1)
                                           { 
                                               temp_table[q][j][k] = 0;
                                               check_table[q][j]--; 
                                               check++;
                                               cout<<"("<<q<<","<<j<<")c"<<k+1;
                                           }
                                       }
                                   } 
                               }
                               break;
                           }
                       }
                   } 
                }
                if(qualify<2)
                    break;
            }
        }
    }
    //----------------------------------------------------------------------------------------
    //check block-----------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------
    
    int temp_main[9];
    int temp_check[9];
    int temp_temp[9][9];
    for(i=0;i<9;i=i+3)
    {
        for(j=0;j<9;j=j+3)
        {
            //copy to temp-----------------------------------------
            k=0;
            for(m=i;m<i+3;m++)
            {
                for(n=j;n<j+3;n++)
                {
                    temp_main[k] = main_table[m][n];
                    temp_check[k] = check_table[m][n];
                    for(q=0;q<9;q++)
                        temp_temp[k][q] = temp_table[m][n][q]; 
                    k++;
                }
            }
            //----------------------------------------------------
            //check qualify---------------------------------------
            //----------------------------------------------------
            total=0;
            qualify=0;
            for(m=0;m<9;m++)
            {
                if(temp_check[m] > 1)
                    total++;
                if(temp_check[m] == 2)
                    qualify++;
            }
            if(total > 2 && qualify >=2)
            {
                for(m=0;m<9;m++)
                {
                    if(temp_check[m] == 2)
                    {
                        qualify=0;
                        for(n=m;n<9;n++)
                        {
                            if(temp_check[n] == 2)
                                qualify++; 
                        }
                        if(qualify>=2)
                        {
                            for(n=m+1;n<9;n++) 
                            {
                                if(temp_check[n] == 2)
                                {
                                    match=0;
                                    for(k=0;k<9;k++)
                                    {
                                        if(temp_temp[m][k] == temp_temp[n][k])
                                            match++;
                                    }
                                    if(match==9)
                                    {
                                        for(q=0;q<9;q++)
                                        {
                                            if(q != m && q != n)
                                            {
                                                for(k=0;k<9;k++)
                                                {
                                                    if(temp_temp[m][k] == 1 && temp_temp[q][k] == 1)
                                                        {
                                                            temp_temp[q][k] = 0;
                                                            temp_check[q]--;
                                                            check++;
                                                            cout<<"("<<i<<","<<j<<","<<q<<")b"<<k+1;
                                                        }
                                                }
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    } 
                    if(qualify < 2)
                        break;
                } 
            }
            //---------------------------------------------------------------------
            //copy backup to main_table--------------------------------------------
            //---------------------------------------------------------------------
            k=0;
            for(m=i;m<i+3;m++)
            {
                for(n=j;n<j+3;n++)
                {
                    main_table[m][n] = temp_main[k];
                    check_table[m][n] = temp_check[k];
                    for(q=0;q<9;q++)
                        temp_table[m][n][q] = temp_temp[k][q];
                    k++;
                }
            }
        }
    }
    
return check;
}

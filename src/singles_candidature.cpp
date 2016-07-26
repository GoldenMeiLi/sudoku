#include<iostream>
#include"candidates.h"


using std::cout;
int singles_candidature()
{
    int i,j,k,num,check(0);

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(check_table[i][j] == 1)
            {
                for(k=0;k<9;k++)
                {
                    if(temp_table[i][j][k] == 1)
                    num = k + 1;
                }
                candidates(i,j,num);
                check++;
            }
        }
    }

return check;
}

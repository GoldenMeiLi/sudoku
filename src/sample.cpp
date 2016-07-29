#include<iostream>
#include<fstream>
#include"candidates.h"


using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;

//
int main_table[9][9];
int check_table[9][9];
int temp_table[9][9][9];
int total(81);
//
void print_table();
void print_check();


int main()
{
    int i,j,k;
    char test_list[82]; 
    char temp_list[10];
    fstream samp_file;

    samp_file.open("sample.txt",ios::in);
    samp_file.getline(test_list,82);
    k = 0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            main_table[i][j] = test_list[k]-48;
            k++;
        }
    }
    samp_file.close();
    samp_file.open("temp_table.txt",ios::in);
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
            check_table[i][j] = 0;
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            samp_file.getline(temp_list,'\n');
            for(k=0;k<9;k++)
            {
                if(temp_list[k] == '1')
                {
                    check_table[i][j]++;
                    temp_table[i][j][k] = 1;
                }
            }
            if(check_table[i][j] ==0)
                total--;
        }
    }
    samp_file.close();
    /* 
    print_check();
    naked_pairs();
    //print_check();
    cout<<endl;
    print_check();
    cout<<endl;
    //singles_candidature();
    //print_table();
    cout<<total<<endl;
    */ 
    
    while(total>0)
    {
        if(singles_candidature())
            continue;
        if(hidden_singles_candidature())
            continue;
        if(naked_pairs())
            continue;
        if(single_sector_candidates())
            continue;
        
        cout<<"error"<<endl;
        break;
    }
    
    //print_check();
    //print_table();
    check_sudoku();
return 0;
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

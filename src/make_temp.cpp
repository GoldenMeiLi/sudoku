#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;


int main()
{
    int i,j,k,m;
    char temp_list[10] = "000000000";
    int tmp;
    fstream temp_file("temp_table.txt",ios::out);

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            for(k=0;k<9;k++) 
            {
                temp_list[k] = '0';
            }
            do{
                cout<<"("<<i+1<<","<<j+1<<"):";
                cin>>tmp;
                if(tmp>0 && tmp<=9)
                {
                    if(temp_list[tmp-1] == '0')
                        temp_list[tmp-1] = '1';
                    else
                        temp_list[tmp-1] = '0';
                }
                else if(tmp > 9)
                {
                    for(m=0;m<9;m++)
                        if(temp_list[m] == '1')
                            cout<<m+1;
                    cout<<endl;
                }
            }while(tmp != 0);
            temp_file<<temp_list<<endl;
        }
    }
    temp_file.close();

return 0;
}

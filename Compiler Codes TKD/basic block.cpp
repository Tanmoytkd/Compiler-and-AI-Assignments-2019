#include<iostream>
#include<cstring>
#include<string>
#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
#include<map>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string add_code[100],temp,input_str;
    int block[100][5];

    bool leader[100]= {0},b1 = 0;
    int count = 1 ;
    printf("Enter 3 Address Codes :\n");
    printf("%d.\t",count);
    while(getline(cin,input_str))
    {
        if(input_str.size()==0)
        {
            printf("\n%d\t",count);
            continue;
        }

        if(b1 == 0)
        {
            b1 = 1;
            leader[count]=1;
        }
        int pos = input_str.find("goto",0);
        if(pos != -1)
        {
            //printf("Bul\n");
            int len = input_str.size();
            char line_num[10];
            int z = 0;
            for(int i = pos+5; i<=len; i++)
            {
                if(isdigit(input_str[i]))
                {
                    line_num[z++]=input_str[i];
                }
                else
                {
                    line_num[z] = '\n';
                    int line = atoi(line_num);
                    //printf("-> %d\n",line);
                    leader[line]=1;
                    break;
                }
            }

            leader[count+1] = 1;
        }
        add_code[count] =  input_str;
        count++;
        printf("%d.\t",count);
    }
    printf("\n\nBsic Block :\n");
    int block_count = 1;
    for(int i=1; i<count; i++)
    {
        if(leader[i]==1 && i == 1)
        {
            block[block_count][0] = 1;
        }
        if(leader[i]==1 && i != 1)
        {
            block[block_count][1] = i-1;
            block_count++;
            block[block_count][0] = i;
        }


    }
    block[block_count][1] = count-1;

    printf("\nNo\tStart\tEnd:\n");
    for(int i = 1 ; i<=block_count ; i++)
    {
        printf("%d\t%d\t%d\n",i,block[i][0],block[i][1]);
    }

    return 0;
}

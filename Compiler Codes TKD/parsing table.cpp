#include <bits/stdc++.h>
using namespace std;

char g[10][20],st[10][20],first[20][20],follo[20][20];
int a=0,e,i,t,b,c,n,k,l=0,j,s,m,p;

int main()
{



    printf("Enter the no. of coordinates\n");
    scanf("%d",&n);
    printf("Enter the productions in a grammar\n");
    getchar();
    for(i=0; i<n; i++){
        gets(st[i]);
    }

    printf("Enter the first in grammars\n");

    for(i=0; i<n; i++)
        scanf("%s",first[i]);
    printf("Enter the follow in grammars\n");
    for(i=0; i<n; i++)
        scanf("%s",follo[i]);

    s=0;
    for(i=0; i<n; i++)
    {

        j=3;


        while(st[i][j]!='\0')
        {


            if((st[i][j-1]=='|')||(j==3))
            {
                for(p=0; p<=2; p++)
                {
                    g[s][p]=st[i][p];
                }
                t=j;
                for(p=3; ((st[i][j]!='|')&&(st[i][j]!='\0')); p++)
                {
                    g[s][p]=st[i][j];
                    j++;
                }
                g[s][p]='\0';
                if(st[i][k]=='@')
                {
                    b=0;
                    a=0;
                    while(st[a][0]!=st[i][0])
                    {
                        a++;
                    }
                    while(follo[a][b]!='\0')
                    {
                        printf("M[%c,%c]=%s\n",st[i][0],follo[a][b],g[s]);
                        b++;
                    }
                }
                else if(!((st[i][t]>64)&&(st[i][t]<91)))
                    printf("M[%c,%c]=%s\n",st[i][0],st[i][t],g[s]);
                else
                {
                    b=0;
                    a=0;
                    while(st[a][0]!=st[i][3])
                    {
                        a++;
                    }
                    while(first[a][b]!='\0')
                    {
                        printf("M[%c,%c]=%s\n",st[i][0],first[a][b],g[s]);
                        b++;
                    }
                }
                s++;
            }
            if(st[i][j]=='|')
                j++;
        }
    }
//    getch();
}
/*
input:
2
S->CC
C->eC | d
ed
ed
$
ed$

output:
M [S, e] =S->CC
M [S, d] =S->CC
M [C, e] =C->eC
M [C, d] =C->d

input:
3
A->Sd
S->a|C
C->b
a
a
b
$
d
d
*/

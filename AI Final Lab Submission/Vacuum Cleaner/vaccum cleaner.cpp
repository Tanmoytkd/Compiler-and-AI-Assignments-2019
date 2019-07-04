#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cout<<"Enter grid size (row and column)"<<endl;
    cin>>n>>m;
    int dirt=rand()%(n*m)+1;
    int grid[n+7][m+7];
    memset(grid,0,sizeof grid);
    for(int i=1;i<=dirt;i++)
    {
        int x=rand()%n+1;
        int y=rand()%m+1;
        grid[x][y]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1,k=m;j<=m,k>=1;j++,k--)
        {
            if(i%2==1)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                    cout<<"CLEAN"<<endl;
                }
                if(j<m)
                {
                    cout<<"RIGHT"<<endl;
                }
                else
                {
                    cout<<"DOWN"<<endl;
                }
            }
            else
            {
                if(grid[i][k]==1)
                {
                    grid[i][k]=0;
                    cout<<"CLEAN"<<endl;
                }
                if(k>1)
                {
                    cout<<"LEFT"<<endl;
                }
                else
                {
                    cout<<"DOWN"<<endl;
                }
            }
        }
    }
}

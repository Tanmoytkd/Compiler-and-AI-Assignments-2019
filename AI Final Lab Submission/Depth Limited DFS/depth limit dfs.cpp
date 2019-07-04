#include<bits/stdc++.h>

using namespace std;

vector <int> adj[100];

int s,d,lim,ret=-1;
int vis[100];

int depth_limit_dfs(int x,int cnt)
{
    vis[x]=1;
    if(cnt<lim)
    {
        for(int i=0;i<adj[x].size();i++)
        {
            int v=adj[x][i];
            if(vis[v]==0)
            {
                //cout<<v<<' '<<d<<' '<<cnt+1<<endl;
                if(v==d)
                    ret= cnt+1;
                depth_limit_dfs(v,cnt+1);
            }
        }
    }
    return ret;
}

int main()
{
    int n,e,x,y;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    cout<<"Give the edges in u-v format"<<endl;
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"Give the starting node and ending node"<<endl;
    cin>>s>>d;
    cout<<"Give depth limit"<<endl;
    cin>>lim;
    int ans=depth_limit_dfs(s,0);
    if(ans==-1)
    {
        cout<<"The ending node is not within "<<lim<<" depth"<<endl;
    }
    else
    {
        cout<<"The ending node is at "<<ans<<" depth"<<endl;
    }
    return 0;
}

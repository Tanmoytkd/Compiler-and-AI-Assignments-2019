#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cout<<"Enter grid size (row and column)"<<endl;
    cin>>n>>m;
    cout<<"Enter position of the agent"<<endl;
    int posx,posy,dest_x,dest_y;
    cin>>posx>>posy;
    cout<<"Enter destination"<<endl;
    cin>>dest_x>>dest_y;
    cout<<"Needed moves: ";
    if(posx<=dest_x)
    {
        int right= dest_x-posx;
        for(int i=1;i<=right;i++)
        {
            cout<<"R";
        }
    }
    else
    {
        int left=posx-dest_x;
        for(int i=1;i<=left;i++)
        {
            cout<<"L";
        }
    }
    if(posy<=dest_y)
    {
        int up= dest_y-posy;
        for(int i=1;i<=up;i++)
        {
            cout<<"U";
        }
    }
    else
    {
        int down=posy-dest_y;
        for(int i=1;i<=down;i++)
        {
            cout<<"D";
        }
    }
    return 0;
}

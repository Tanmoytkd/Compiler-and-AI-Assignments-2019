#include<bits/stdc++.h>
using namespace std;
void terminal(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(islower(s[i]))
        {
            cout<<s[i]<<",";
        }

    }
}
void non_terminal(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(isupper(s[i]))
        {
            cout<<s[i]<<",";
        }

    }
}
int main()
{
    string s;
    cin>>s;
    cout<<"terminal: ";
    terminal(s);
    cout<<endl;
cout<<"non-terminal: ";
    non_terminal(s);
 cout<<endl;
    return 0;
}
/*
aE+bcD|aE+eIT
*/

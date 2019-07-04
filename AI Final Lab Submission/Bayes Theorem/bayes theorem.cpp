#include<bits/stdc++.h>

using namespace std;

int main()
{
    double pA,pB,pBgivenA,pAgivenB;
    cout<<"Give P(A) and P(B)"<<endl;
    cin>>pA>>pB;
    cout<<"If you want to give P(B|A) then press 1, or if you want to give P(A|B) press 2"<<endl;
    int x;
    cin>>x;
    if(x==1)
    {
        cout<<"Give P(B|A)"<<endl;
        cin>>pBgivenA;
        cout<<"P(A|B) = "<< (pA*pBgivenA)/pB<<endl;
    }
    else
    {
        cout<<"Give P(A|B)"<<endl;
        cin>>pAgivenB;
        cout<<"P(B|A) = "<<(pB*pAgivenB)/pA<<endl;
    }
    return 0;
}

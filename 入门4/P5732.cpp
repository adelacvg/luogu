#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int tri[110][110]{1};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j!=1)cout<<" ";
            cout<<tri[i][j];
        }
        cout<<endl;
    }
}
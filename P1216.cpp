#include<bits/stdc++.h>
using namespace std;
int m[1010][1010];

int main()
{
    int r;
    cin>>r;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>m[i][j];
        }
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
        {
            m[i][j]+=max(m[i-1][j],m[i-1][j-1]);
        }
    }
    int ans=0;
    for(int i=1;i<=r;i++)
    {
        ans=max(ans,m[r][i]);
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int nSm(int n,int m)
{
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j-1]+j*dp[i-1][j];
        }
    }
    return dp[n][m];
}

int nCm(int n,int m)
{
    int ans=1;
    for(int i=1;i<=m;i++)
    {
        ans=ans*(n-m+i)/i;
    }
    return ans;
}
int fac(int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
        ans=ans*i;
    return ans;
}

int main()
{
    int n,r;
    cin>>n>>r;
    if(n<r)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<fac(r)*nSm(n,r)<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int a[600];
int dp[600][600];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=INT_MAX;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][i]=1;
    }
    for(int i=1;i<n;i++)
        dp[i][i+1]=(a[i]==a[i+1]?1:2);
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            auto j=i+len;
            if(j>n)
                break;
            if(a[i]==a[j])
                dp[i][j]=dp[i+1][j-1];
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],
                dp[i][k]+dp[k+1][j]);
        }
    }
    cout<<dp[1][n]<<endl;
}
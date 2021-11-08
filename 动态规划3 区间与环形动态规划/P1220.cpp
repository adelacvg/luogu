#include<bits/stdc++.h>
using namespace std;
int a[55],b[55];
int dp[55][55][2];
int sum[55];

int main()
{
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sum[i]=sum[i-1]+b[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<=1;k++)
                dp[i][j][k]=1e5;
    dp[c][c][0]=0;
    dp[c][c][1]=1;
    for(int len=1;len<=n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            auto j=i+len;
            if(j>n)
                break;
            dp[i][j][0]=min(dp[i+1][j][0]+
            (a[i+1]-a[i])*(sum[i]+sum[n]-sum[j]),
            dp[i+1][j][1]+
            (a[j]-a[i])*(sum[i]+sum[n]-sum[j]));
            dp[i][j][1]=min(dp[i][j-1][1]+
            (a[j]-a[j-1])*(sum[i-1]+sum[n]-sum[j-1]),
            dp[i][j-1][0]+
            (a[j]-a[i])*(sum[i-1]+sum[n]-sum[j-1]));
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1])<<endl;
}
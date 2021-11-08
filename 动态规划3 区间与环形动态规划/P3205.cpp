#include<bits/stdc++.h>
using namespace std;
constexpr int mod=19650827;
int a[1010];
int dp[1010][1010][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    if(n==2)
    {
        cout<<2<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][i][0]=dp[i][i][1]=1;
    }
    for(int i=1;i<n;i++)
        if(a[i]<a[i+1])
            dp[i][i+1][0]=dp[i][i+1][1]=1;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            auto j=i+len;
            if(j>n)
                break;
            if(a[i]<a[i+1])
                dp[i][j][0]=(dp[i][j][0]+dp[i+1][j][0])%mod;
            if(a[i]<a[j])
                dp[i][j][0]=(dp[i][j][0]+dp[i+1][j][1])%mod;
            if(a[j]>a[j-1])
                dp[i][j][1]=(dp[i][j][1]+dp[i][j-1][1])%mod;
            if(a[j]>a[i])
                dp[i][j][1]=(dp[i][j][1]+dp[i][j-1][0])%mod;
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%mod;
}
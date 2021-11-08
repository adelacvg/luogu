#include<bits/stdc++.h>
using namespace std;
using i64=long long;
i64 lose[1010],win[1010],use[1010];
i64 dp[1010][1010];

int main()
{
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>lose[i]>>win[i]>>use[i];
    }
    for(int i=x;i>=0;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i+use[j]<=x)
                dp[i][j]=max(dp[i+use[j]][j-1]+win[j], dp[i][j-1]+lose[j]);
            else
                dp[i][j]=dp[i][j-1]+lose[j];
        }
    }
    cout<<dp[0][n]*5<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>v[i][j];
        }
    }
    int  ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        vector<int> pre(n+1,0);
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                pre[k]+=v[j][k];
            }
            vector<int> dp(n+1,0);
            for(int x=1;x<=n;x++)
            {
                dp[x]=max(dp[x],dp[x-1]+pre[x]);
                ans=max(ans,dp[x]);
            }
        }
    }
    cout<<ans<<endl;
}
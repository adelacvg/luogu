#include<bits/stdc++.h>
using namespace std;
int a[22][22];
int w[22],dp[22];
int pre[22];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        dp[i]=w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j][i])
            {
                if(dp[i]<dp[j]+w[i])
                {
                    dp[i]=dp[j]+w[i];
                    pre[i]=j;
                }
            }
        }
    }
    int st=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>dp[st])
        {
            st=i;
        }
    }
    ans=dp[st];
    vector<int> v;
    while(st)
    {
        v.emplace_back(st);
        st=pre[st];
    }
    reverse(begin(v),end(v));
    for(auto i:v)
        cout<<i<<" ";
    cout<<'\n'<<ans<<'\n';
}
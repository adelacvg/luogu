#include<bits/stdc++.h>
using namespace std;
using i64=long long;

i64 a[10010],b[10010];
i64 dp[10000010];
int main()
{
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i>=a[j])
                dp[i]=max(dp[i],dp[i-a[j]]+b[j]);
        }
    }
    cout<<dp[t]<<endl;
}
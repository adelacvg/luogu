#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int dp[1010];

int main()
{
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=t;i>=1;i--)
        {
            if(i>=a[j])
                dp[i]=max(dp[i],dp[i-a[j]]+b[j]);
        }
    }
    cout<<dp[t]<<endl;
}
#include<bits/stdc++.h>
using namespace std;
using i64=long long;

i64 tree[40];
i64 dp[100][100];
int root[100][100];
void dfs(int l,int r)
{
    if(l>r)
        return;
    if(l==r)
    {
        cout<<l<<" ";
        return;
    }
    auto t=root[l][r];
    cout<<t<<" ";
    dfs(l,t-1);
    dfs(t+1,r);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dp[i][i];
        dp[i][i-1]=1;
        dp[i+1][i]=1;
        root[i][i]=i;
    }
    for(int len=1;len<=n;len++)
    {
        for(int i=1;i+len<=n;i++)
        {
            auto j=i+len;
            for(int k=i;k<=j;k++)
            {
                auto t=dp[i][k-1]*dp[k+1][j]+dp[k][k];
                if(t>dp[i][j])
                {
                    dp[i][j]=t;
                    root[i][j]=k;
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    dfs(1,n);
}
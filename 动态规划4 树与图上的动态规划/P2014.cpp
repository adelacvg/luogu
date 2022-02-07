#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> edge[330];
int dp[330][330];

void dp_dfs(int x)
{
    for(auto i:edge[x])
    {
        dp_dfs(i);
        for(int j=m+1;j>=1;j--)
        {
            for(int k=0;k<j;k++)
            {
                dp[x][j]=max(dp[x][j],dp[i][k]+dp[x][j-k]);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int s,k;
        cin>>s>>k;
        dp[i][1]=k;
        edge[s].emplace_back(i);
    }
    dp_dfs(0);
    cout<<dp[0][m+1]<<'\n';
}
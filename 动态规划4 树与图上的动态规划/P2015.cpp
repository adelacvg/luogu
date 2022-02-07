#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<tuple<int,int>> edge[330];
int dp[330][330];
int vis[110];

void dp_dfs(int x)
{
    vis[x]=1;
    for(auto [i,v]:edge[x])
    {
        if(!vis[i])
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
}
void init_dfs(int x)
{
    vis[x]=1;
    for(auto [i,v]:edge[x])
    {
        if(!vis[i])
        {
            dp[i][1]=v;
            init_dfs(i);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].emplace_back(b,c);
        edge[b].emplace_back(a,c);
    }
    init_dfs(1);
    memset(vis,0,sizeof(vis));
    dp_dfs(1);
    cout<<dp[1][m+1]<<'\n';
}
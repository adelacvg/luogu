#include<bits/stdc++.h>
using namespace std;
void dfs(int root,vector<int>& ans,vector<bool>& flag,
vector<vector<int>>& e,int mx)
{
    ans[root]=mx;
    flag[root]=true;
    for(auto i:e[root])
    {
        if(!flag[i])
            dfs(i,ans,flag,e,mx);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> e(n+1,vector<int>{});
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        e[v].emplace_back(u);
    }
    vector<int> ans(n+1,0);
    vector<bool> flag(n+1,0);
    for(int i=1;i<=n;i++)
        ans[i]=i;
    for(int i=n;i>=1;i--)
    {
        if(!flag[i])
            dfs(i,ans,flag,e,i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
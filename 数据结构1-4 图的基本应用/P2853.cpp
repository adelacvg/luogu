#include<bits/stdc++.h>
using namespace std;
void dfs(int x,vector<vector<int>>& e,
vector<bool>& flag,vector<int>& cnt)
{
    for(auto i:e[x])
    {
        if(!flag[i])
        {
            flag[i]=1;
            cnt[i]++;
            dfs(i,e,flag,cnt);
        }
    }
}

int main()
{
    int k,n,m;
    cin>>k>>n>>m;
    vector<int> cow;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        cow.emplace_back(x);
    }
    vector<vector<int>> e(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        e[u].emplace_back(v);
    }
    vector<bool> flag(n+1,0);
    vector<int> cnt(n+1,0);
    for(auto i:cow)
    {
        flag[i]=1;
        cnt[i]++;
        dfs(i,e,flag,cnt);
        fill(begin(flag),end(flag),0);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==k)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
constexpr const int maxn = 1e5+10;
vector<int> e[maxn];
int dis[maxn];
int maxd[maxn];
int dep[maxn];
int kernel;
int l,r;
int maxdep;
int pre[maxn];
int flag[maxn];
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    if(dep[x]>maxdep)
    {
        maxdep=dep[x];
        l=x;
    }
    for(auto i:e[x])
    {
        if(i!=fa)
            dfs(i,x);
    }
}
void dfs2(int x,int fa)
{
    dep[x]=dep[fa]+1;
    if(dep[x]>maxdep)
    {
        maxdep=dep[x];
        r=x;
    }
    for(auto i:e[x])
    {
        if(i!=fa)
        {
            pre[i]=x;
            dfs2(i,x);
        }
    }
}
void dfs3(int x,int fa)
{
    dep[x]=dep[fa]+1;
    maxd[x]=dep[x];
    for(auto i:e[x])
    {
        if(i!=fa)
        {
            dfs3(i,x);
            maxd[x]=max(maxd[i],maxd[x]);
        }
    }
    dis[x]=maxd[x]-dep[x];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1,0);
    maxdep=0;
    dfs2(l,0);
    int len=(dep[r]-dep[l])/2;
    kernel = r;
    while(len--)
        kernel=pre[kernel];
    dfs3(kernel,0);
    priority_queue<pair<int,int>> q;
    q.emplace(0,kernel);
    while(k--)
    {
        auto [dist,index]=q.top();
        flag[index]=1;
        q.pop();
        for(auto i:e[index])
            if(!flag[i])
                q.emplace(dis[i],i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!flag[i])
        {
            ans=max(ans,dis[i]);
        }
    }
    cout<<ans+1<<endl;
}
#include<bits/stdc++.h>
using namespace std;
constexpr const int maxn=5e4+10;
vector<int> e[maxn];
int sz[maxn];
int dis[maxn]={-1};
int f[maxn];
int g[maxn];
int n;
int ans=INT32_MAX;
int pos=1;
int dfs(int now,int fa)
{
    dis[now]=dis[fa]+1;
    sz[now]=1;
    for(auto i:e[now])
        if(i!=fa)
            sz[now]+=dfs(i,now);
    return sz[now];
}
void dfs2(int now,int fa)
{
    if(now!=1)
        g[now]=g[fa]-sz[now]+n-sz[now];
    if(g[now]<ans)
    {
        ans=g[now];
        pos=now;
    }
    if(g[now]==ans)
    {
        pos=min(pos,now);
    }
    for(auto i:e[now])
        if(i!=fa)
            dfs2(i,now);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        g[1]+=dis[i];
    dfs2(1,0);
    cout<<pos<<" "<<ans<<endl;
}
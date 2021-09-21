#include<bits/stdc++.h>
using namespace std;

constexpr const int maxn = 1000000;
int fa[maxn][40],dep[maxn];
vector<int> e[maxn];
int n,m;

void dfs(int now,int father)
{
    fa[now][0]=father;
    dep[now]=dep[father]+1;
    int ub=floor(log2(dep[now]-1));
    for(int i=1;i<=ub;i++)
    {
        fa[now][i]=fa[fa[now][i-1]][i-1];
    }
    for(auto i:e[now])
        if(i!=father)
            dfs(i,now);
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])
    {
        swap(x,y);
    }
    while(dep[x]>dep[y])
    {
        x=fa[x][int(floor(log2(dep[x]-dep[y])))];
    }
    if(x==y)
        return x;
    for(int k=floor(log2(dep[x]-1));k>=0;k--)
    {
        if(fa[x][k]!=fa[y][k])
        {
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}
int dis(int a,int b)
{
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}
int main()
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1,0);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int p=lca(lca(a,b),c);
        int cost=dis(p,a)+dis(p,b)+dis(p,c);
        cout<<p<<" "<<cost<<'\n';
    }
}
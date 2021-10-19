#include<bits/stdc++.h>
using namespace std;

constexpr const int maxn = 1000000;
int fa[maxn][40],dep[maxn];
vector<int> e[maxn];
int n,m;
vector<int> v;

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
    ios::sync_with_stdio(0);
    cin.tie(0);
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
        vector<int> p_candidate{lca(a,b),lca(b,c),lca(a,c)};
        int cost=INT_MAX;
        int p=1;
        for(auto p_t:p_candidate)
        {
            int cost_t=dis(p_t,a)+dis(p_t,b)+dis(p_t,c);
            if(cost_t<cost)
            {
                cost=cost_t;
                p=p_t;
            }
        }
        cout<<p<<" "<<cost<<'\n';
    }
}
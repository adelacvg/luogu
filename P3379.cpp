#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=1000000;
int fa[maxn][40],dep[maxn],lg[maxn];
vector<int> e[maxn];
int n,m,s;


void dfs(int now,int father)
{
    fa[now][0]=father;
    dep[now]=dep[father]+1;
    int ub=lg[dep[now]-1]-1;
    for(int i=1;i<=ub;i++)
        fa[now][i]=fa[fa[now][i-1]][i-1];
    for(auto i:e[now])
        if(i!=father)
            dfs(i,now);
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    while(dep[x]>dep[y])
        x=fa[x][lg[dep[x]-dep[y]]-1];
    if(x==y)
        return x;
    for(int k=lg[dep[x]-1]-1;k>=0;k--)
    {
        if(fa[x][k]!=fa[y][k])
        {
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>s;
    init();
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    int a,b;
    dfs(s,0);
    while(m--)
    {
        cin>>a>>b;
        cout<<lca(a,b)<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=1000000;
int fa[maxn][40],dep[maxn];
vector<int> e[maxn];
int n,m,s;


void dfs(int now,int father)
{
    fa[now][0]=father;
    dep[now]=dep[father]+1;
    for(int i=1;i<=floor(log2(dep[now]-1));i++)
        fa[now][i]=fa[fa[now][i-1]][i-1];
    for(i:e[now])
        if(i!=father)
            dfs(i,now);
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    while(dep[x]>dep[y])
        x=fa[x][floor(log2(dep[x]-dep[y]))];
    if(x==y)
        return x;
    for(int k=floor(log2(depth[x]-1));k>=0;k--)
    {
        if(fa[x][k]!=fa[y][k])
        {
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>s;
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    int a,b;
    while(m--)
    {
        cin>>a>>b;
        cout<<lca(a,b)<<'\n';
    }

}
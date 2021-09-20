#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=1000000;
int fa[maxn][40],dep[maxn];
vector<int> e[maxn];
int flag[100010][40][2];
int fl[100010][2];
int n,m,s;


void dfs(int now,int father)
{
    flag[now][0][0]=fl[now][0]|fl[father][0];
    flag[now][0][1]=fl[now][1]|fl[father][1];
    fa[now][0]=father;
    dep[now]=dep[father]+1;
    int ub=floor(log2(dep[now]-1));
    for(int i=1;i<=ub;i++)
    {
        fa[now][i]=fa[fa[now][i-1]][i-1];
        flag[now][i][0]=flag[fa[now][i-1]][i-1][0]|flag[now][i-1][0];
        flag[now][i][1]=flag[fa[now][i-1]][i-1][1]|flag[now][i-1][1];
    }
    for(auto i:e[now])
        if(i!=father)
            dfs(i,now);
}
int lca(int x,int y,int kk)
{
    int ans=fl[x][kk]|fl[y][kk];
    if(dep[x]<dep[y])
        swap(x,y);
    while(dep[x]>dep[y])
    {
        ans|=flag[x][int(floor(log2(dep[x]-dep[y])))][kk];
        x=fa[x][int(floor(log2(dep[x]-dep[y])))];
    }
    if(x==y)
        return ans;
    for(int k=floor(log2(dep[x]-1));k>=0;k--)
    {
        if(fa[x][k]!=fa[y][k])
        {
            ans|=flag[x][k][kk];
            ans|=flag[y][k][kk];
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return ans|flag[x][0][kk];
}

int main()
{
    // ifstream cin("P5836_2.in");
    // ofstream cout("out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='H')
        fl[i+1][0]=1;
        else
        fl[i+1][1]=1;
    }
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    int a,b;
    char c;
    dfs(1,0);
    while(m--)
    {
        cin>>a>>b>>c;
        if(c=='H')
            cout<<lca(a,b,0);
        else
            cout<<lca(a,b,1);
    }
}
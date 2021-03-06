#include<bits/stdc++.h>
using namespace std;
using i64 = unsigned long long;
const int maxn = 1e6+10;
vector<int> e[maxn];
int sz[maxn],sz2[maxn];
int hson[maxn],hson2[maxn],hson_root[maxn],pr[maxn];
int hsonjmp[maxn][20];
i64 ans;
int f[maxn];


void dfs1(int x,int fa)
{
    sz[x]=1;
    pr[x]=fa;
    for(auto son: e[x])
    {
        if(son==fa)
            continue;
        dfs1(son,x);
        sz[x]+=sz[son];
        if(sz[son]>sz[hson[x]])
        {
            hson2[x]=hson[x];
            hson[x]=son;
        }
        else if(sz[son]>sz[hson2[x]])
        {
            hson2[x]=son;
        }
    }
    hsonjmp[x][0]=hson[x];
    for(int i=1;i<=19;i++)
    {
        hsonjmp[x][i]=hsonjmp[hsonjmp[x][i-1]][i-1];
    }
}
int judge(int x,int sum)
{
    return x*(max(sz2[hson_root[x]],sum-sz2[x])<=sum/2);
}
void dfs2(int x,int fa)
{
    for(auto son:e[x])
    {
        if(son==fa)
            continue;
        sz2[x]=sz[1]-sz[son];
        f[x]=0;
        f[son]=0;
        if(son==hson[x])
            hson_root[x]=hson2[x];
        else
            hson_root[x]=hson[x];
        if(sz2[fa]>sz2[hson_root[x]])
            hson_root[x]=fa;
        hsonjmp[x][0]=hson_root[x];
        for(int i=1;i<=19;i++)
        {
            hsonjmp[x][i]=hsonjmp[hsonjmp[x][i-1]][i-1];
        }
        int t=x;
        for(int i=19;i>=0;i--)
        {
            if(sz2[x]-sz2[hsonjmp[t][i]]<=sz2[x]/2)
                t=hsonjmp[t][i];
        }
        ans+=judge(hson_root[t],sz2[x])+judge(t,sz2[x])+judge(f[t],sz2[x]);
        t=son;
        for(int i=19;i>=0;i--)
        {
            if(sz2[son]-sz2[hsonjmp[t][i]]<=sz2[son]/2)
                t=hsonjmp[t][i];
        }
        ans+=judge(hson_root[t],sz2[son])+judge(t,sz2[son])+judge(f[t],sz2[son]);
        f[x]=son;
        dfs2(son,x);
    }
    hson_root[x]=hsonjmp[x][0]=hson[x];
    f[x]=pr[x];
    for(int i=1;i<=19;i++)
        hsonjmp[x][i]=hsonjmp[hsonjmp[x][i-1]][i-1];
    sz2[x]=sz[x];
}
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            hson[i]=0;
            f[i]=0;
            pr[i]=0;
        }
        for(int i=1;i<=n;i++)
            e[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        dfs1(1,0);
        for(int i=1;i<=n;i++)
        {
            sz2[i]=sz[i];
            hson_root[i]=hson[i];
            f[i]=pr[i];
        }
        dfs2(1,0);
        cout<<ans<<'\n';
    }
}
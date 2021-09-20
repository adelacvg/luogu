#include<bits/stdc++.h>
using namespace std;
constexpr const int maxn=5e5+10;
vector<tuple<int,int>> e[maxn];
int dis[maxn];
int l,r;
int maxdis;
int pre[maxn];
int outermax[maxn];
int flag[maxn];
int disout[maxn];


void dfs1(int x,int fa)
{
    if(dis[x]>maxdis)
    {
        maxdis=dis[x];
        l=x;
    }
    for(auto[v,w]:e[x])
    {
        if(v!=fa)
        {
            dis[v]=dis[x]+w;
            dfs1(v,x);
        }
    }
}
void dfs2(int x,int fa)
{
    if(dis[x]>maxdis)
    {
        maxdis=dis[x];
        r=x;
    }
    for(auto[v,w]:e[x])
    {
        if(v!=fa)
        {
            dis[v]=dis[x]+w;
            pre[v]=x;
            dfs2(v,x);
        }
    }
}
int dfs3(int x,int fa)
{
    int max_dis=disout[x];
    for(auto [v,w]:e[x])
    {
        if(!flag[v]&&v!=fa)
        {
            disout[v]=disout[x]+w;
            max_dis=max(max_dis,dfs3(v,x));
        }
    }
    return max_dis;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,s;
    cin>>n>>s;
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
    dfs1(1,0);
    maxdis=0;
    dis[l]=0;
    dfs2(l,0);
    vector<int> diameter;
    int ed=r;
    while(ed!=l)
    {
        flag[ed]=1;
        diameter.emplace_back(ed);
        ed=pre[ed];
    }
    diameter.emplace_back(l);
    flag[l]=1;
    int len=diameter.size();
    reverse(begin(diameter),end(diameter));
    for(auto i:diameter)
    {
        outermax[i]=dfs3(i,0);
    }
    int ans=INT_MAX;
    int i=0,j=0;
    while(i<len&&j<len)
    {
        while(j<len&&
        dis[diameter[j]]-dis[diameter[i]]<=s)
        {
            j++;
        }
        ans=min(ans,max(dis[diameter[i]],
        dis[diameter[len-1]]-dis[diameter[j-1]]));
        i++;
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,outermax[i]);
    }
    cout<<ans<<endl;
    
}
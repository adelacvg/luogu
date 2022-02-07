#include<bits/stdc++.h>
using namespace std;
int n,m;
constexpr const int N=8e4+10;
constexpr const int E=2e5+10;
vector<tuple<int,int,int>> e[N];
vector<tuple<int,int>>belong_e[N];//u->v w k
vector<tuple<int,int,int,int>> edge;
vector<long long> dfn(N),low(N),vis(N),belong(N),belong_vis(N),sum(N),ind(N);
vector<int> topo_list;
vector<long long> dis(N);
int cnt,tot;
stack<int> st;

void tarjan(int u)
{
    dfn[u]=low[u]=++cnt;
    vis[u]=1;
    st.push(u);
    for(auto [v,w,k]:e[u])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        tot++;
        int v;
        while(v=st.top())
        {
            st.pop();
            belong[v]=tot;
            vis[v]=0;
            if(u==v)
                break;
        }
    }
}
void topo()
{
    queue<int> q;
    for(int i=1;i<=tot;i++)
    {
        if(ind[i]==0)
            q.emplace(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        topo_list.emplace_back(u);
        for(auto [v,w]:belong_e[u])
        {
            ind[v]--;
            if(ind[v]==0)
                q.emplace(v);
        }
    }
}
void longest(int s)
{
    fill(begin(dis),end(dis),INT_MIN);
    dis[s]=sum[s];
    for(auto u:topo_list)
    {
        for(auto [v,w]:belong_e[u])
        {
            dis[v]=max(dis[v],dis[u]+sum[v]+w);
        }
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        double k;
        cin>>u>>v>>w>>k;
        e[u].emplace_back(v,w,k*10);
        edge.emplace_back(u,v,w,k*10);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(auto [u,v,w,k]:edge)
    {
        if(belong[u]==belong[v])
        {
            while(w)
            {
                sum[belong[u]]+=w;
                w=w*k/10;
            }
        }
        else
        {
            belong_e[belong[u]].emplace_back(belong[v],w);
            ind[belong[v]]++;
        }
    }
    int s;
    cin>>s;
    s=belong[s];
    topo();
    longest(s);
    long long ans=0;
    for(int i=1;i<=tot;i++)
        ans=max(ans,dis[i]);
    cout<<ans<<endl;
}
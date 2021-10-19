#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;
constexpr const int maxn=1e6+10;
vector<int> e[maxn];
i64 color[maxn];
i64 color_cnt[maxn];
i64 cnt[maxn];
i64 n;
i64 ans1[maxn],ans2[maxn];
i64 color_pos[maxn];
i64 end_pos_cnt[maxn];
i64 sz[maxn];
void dfs(int x,int fa)
{
    int k=cnt[color[x]];
    sz[x]=1;
    int flag=0,pos=0;
    for(auto i:e[x])
    {
        if(i==fa)
            continue;
        int color_all=cnt[color[x]];
        dfs(i,x);
        ans1[x]+=1ull*sz[x]*sz[i];
        sz[x]+=sz[i];
        // cout<<x<<endl;
        // cout<<color_all<<" "<<cnt[color[x]]<<endl;
        if(color_all!=cnt[color[x]])
        {
            flag++;
            pos=i;
        }
    }
    ans1[x]+=1ull*sz[x]*(n-sz[x]);
    if(k||cnt[color[x]]!=color_cnt[color[x]]-1)
    {
        flag++;
    }
    cnt[color[x]]++;
    if(flag==1)
    {
        // cout<<x<<" "<<"*"<<endl;
        if(end_pos_cnt[color[x]]>2)
            return;
        if(!end_pos_cnt[color[x]])
        {
            // cout<<color[x]<<"  "<<x<<endl;
            color_pos[color[x]]=x;
        }
        else
        {
            int p=pos?n-sz[pos]:sz[x];
            ans2[color[x]]=1ull*sz[color_pos[color[x]]]*p;
        }
        end_pos_cnt[color[x]]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>color[i];
        color_cnt[color[i]]++;
        color_pos[color[i]]=i;
    }
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        if(color_cnt[i]==0)
        {
            cout<<n*(n-1)/2<<'\n';
        }
        else if(color_cnt[i]==1)
        {
            cout<<ans1[color_pos[i]]<<'\n';
        }
        else if(end_pos_cnt[i]==2)
        {
            cout<<ans2[i]<<'\n';
        }
        else
            cout<<0<<'\n';
    }
}
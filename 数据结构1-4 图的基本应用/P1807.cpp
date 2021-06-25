#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> e_out(n+1,
    vector<pair<int,int>>{});
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e_out[u].emplace_back(make_pair(v,-w));
    }
    auto cmp=[](auto& a,auto& b)
    {
        return a.second>b.second;
    };
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    decltype(cmp)> q(cmp);
    q.emplace(make_pair(1,0));
    vector<int> dis(n+1,1e9);
    dis[1]=0;
    while(!q.empty())
    {
        auto [v,w]=q.top();
        q.pop();
        for(auto &[to_v,to_w]:e_out[v])
        {
            if(dis[to_v]>dis[v]+to_w)
            {
                dis[to_v]=dis[v]+to_w;
                q.emplace(make_pair(to_v,dis[to_v]));
            }
        }
    }
    if(dis[n]!=1e9)
    cout<<-dis[n]<<endl;
    else
    cout<<-1<<endl;
}
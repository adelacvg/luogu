#include<bits/stdc++.h>
using namespace std;
long long solve(int i,vector<long long>& w,
vector<vector<long long>>& v)
{
    queue<int> q;
    q.emplace(i);
    long long dissum=0;
    vector<bool> flag(w.size());
    vector<int> dep(w.size(),0);
    flag[i]=true;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(auto x:v[t])
        {
            if(!flag[x])
            {
                flag[x]=true;
                q.emplace(x);
                dep[x]=dep[t]+1;
                dissum+=dep[x]*w[x];
            }
        }
    }
    return dissum;
}

int main()
{
    int n;
    cin>>n;
    vector<long long> w(n+1);
    vector<vector<long long>> v(n+1,vector<long long>{});
    int l,r;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        cin>>l>>r;
        if(l)
        {
            v[l].emplace_back(i);
            v[i].emplace_back(l);
        }
        if(r)
        {
            v[r].emplace_back(i);
            v[i].emplace_back(r);
        }
    }
    long long ans=LONG_LONG_MAX;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,solve(i,w,v));
    }
    cout<<ans<<endl;
}
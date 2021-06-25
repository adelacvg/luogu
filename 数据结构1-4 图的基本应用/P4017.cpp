#include<bits/stdc++.h>
using namespace std;
const int mod = 80112002;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> e_out(n+1,vector<int>{});
    vector<int> d_in(n+1,0);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        e_out[a].emplace_back(b);
        d_in[b]++;
    }
    vector<int> ans(n+1,0);
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(d_in[i]==0)
        {
            q.emplace(i);
            ans[i]=1;
        }
    }
    int res=0;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(auto i:e_out[t])
        {
            d_in[i]--;
            ans[i]=(ans[i]+ans[t])%mod;
            if(d_in[i]==0)
            {
                if(e_out[i].size()==0)
                {
                    res=(res+ans[i])%mod;
                }
                q.emplace(i);
            }
        }
    }
    cout<<res<<endl;
}
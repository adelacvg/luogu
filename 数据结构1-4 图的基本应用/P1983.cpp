#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ifstream cin("P1983_8.in");
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> e(n+1,vector<int>{});
    vector<vector<bool>> fl(n+1,vector<bool>(n+1,0));
    vector<int> ind(n+1,0);
    while(m--)
    {
        int t;
        cin>>t;
        vector<int> high;
        vector<bool> flag(n+1);
        while(t--)
        {
            int x;
            cin>>x;
            flag[x]=1;
            high.emplace_back(x);
        }
        for(int i=high[0];i<=high.back();i++)
        {
            if(!flag[i])
            {
                for(auto j:high)
                {
                    if(!fl[j][i])
                    {
                        fl[j][i]=1;
                        e[j].emplace_back(i);
                        ind[i]++;
                    }
                }
            }
        }
    }
    vector<int> dis(n+1,1);
    vector<int> st;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            st.emplace_back(i);
        }
    }
    queue<int> q;
    for(auto i:st)
    {
        q.emplace(i);
    }
    int ans=1;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(auto i:e[t])
        {
            if(--ind[i]==0)
            {
                q.emplace(i);
                dis[i]=dis[t]+1;
                ans=max(dis[i],ans);
            }
        }
    }
    cout<<ans<<endl;
}
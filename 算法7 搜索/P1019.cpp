#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> v(30,vector<int>());
vector<string> s(30);
map<pair<int,int>,int> dis;
int ans=0;
vector<int> vis(30,0);

void dfs(int x,int len)
{
    // cout<<x<<endl;
    int flag=0;
    for(auto i:v[x])
    {
        if(vis[i]<2)
        {
            flag=1;
            vis[i]++;
            dfs(i,len+s[i].size()-dis[make_pair(x,i)]);
            vis[i]--;
        }
    }
    if(!flag)
    {
        ans=max(ans,len);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    char c;
    cin>>c;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            auto& s1=s[i];
            auto& s2=s[j];
            int len_min=min(s1.size(),s2.size());
            int len_max=max(s1.size(),s2.size());
            for(int k=len_min-1;k>=1;k--)
            {
                if(s1.substr(s1.size()-k,k)==
                s2.substr(0,k))
                {
                    v[i].push_back(j);
                    dis[make_pair(i,j)]=k;
                }
                if(s2.substr(s2.size()-k,k)==
                s1.substr(0,k))
                {
                    v[j].push_back(i);
                    dis[make_pair(j,i)]=k;
                }
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(auto j:v[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<n;i++)
    {
        if(s[i][0]==c)
        {
            vis[i]++;
            dfs(i,s[i].size());
            vis[i]--;
        }
    }
    cout<<ans<<endl;
}
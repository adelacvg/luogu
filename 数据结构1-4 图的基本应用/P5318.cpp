#include<bits/stdc++.h>
using namespace std;
void dfs(int root,vector<vector<int>>& v,vector<bool>& flag)
{
    cout<<root<<" ";
    flag[root]=1;
    for(auto i:v[root])
    {
        if(!flag[i])
            dfs(i,v,flag);
    }
}

void bfs(int root,vector<vector<int>>& v,vector<bool>& flag)
{
    queue<int> q;
    q.emplace(root);
    flag[root]=1;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        cout<<t<<" ";
        for(auto i:v[t])
        {
            if(!flag[i])
            {
                q.emplace(i);
                flag[i]=1;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>{});
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        v[x].emplace_back(y);
    }
    for(auto &i:v)
    {
        sort(begin(i),end(i));
    }
    int root=1;
    vector<bool> flag(n+1,0);
    dfs(root,v,flag);
    cout<<'\n';
    fill(begin(flag),end(flag),0);
    bfs(root,v,flag);
    cout<<'\n';
}
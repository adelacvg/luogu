#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<long long,long long>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(begin(v),end(v),
    [](auto a,auto b){return a.second<b.second;});
    priority_queue<int> q;
    long long now=0;
    int ans=0;
    for(auto [i,j]:v)
    {
        if(!q.empty()&&now+i>j&&i<q.top())
        {
            now-=q.top();
            q.pop();
            q.emplace(i);
            now+=i;
        }
        else if(now+i<=j)
        {
            now+=i;
            ans++;
            q.emplace(i);
        }
    }
    cout<<ans<<'\n';
}
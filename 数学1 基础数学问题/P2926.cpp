#include<bits/stdc++.h>
using namespace std;

vector<int> cnt(1000010);


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+1);
    set<int> s;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        cnt[v[i]]++;
        s.insert(v[i]);
        mx=max(v[i],mx);
    }
    vector<int> ans(1000010,0);
    for(auto i:s)
    {
        for(auto j=i;j<=mx;j+=i)
        {
            ans[j]+=cnt[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[v[i]]-1<<'\n';
    }
    
}
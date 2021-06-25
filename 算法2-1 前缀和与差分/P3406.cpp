#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> pos(m);
    vector<int> v(n+1,0);
    for(int i=0;i<m;i++)
        cin>>pos[i];
    for(int i=0;i<m-1;i++)
    {
        auto l=min(pos[i],pos[i+1]);
        auto r=max(pos[i],pos[i+1]);
        v[l]++;
        v[r]--;
    }
    vector<long long> a(n+1),b(n+1),c(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        v[i]+=v[i-1];
        ans+=min(v[i]*a[i],c[i]+v[i]*b[i]);
    }
    cout<<ans<<endl;
}
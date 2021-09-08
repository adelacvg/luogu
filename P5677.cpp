#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int maxn=3e5+10;
i64 v[maxn],a[maxn],ind[maxn];
i64 n,m;
i64 lowbit(i64 x)
{
    return x&(~x+1);
}
void add(i64 x,i64 k)
{
    while(x<=n)
    {
        v[x]+=k;
        x+=lowbit(x);
    }
}
i64 query(i64 x)
{
    i64 ans=0;
    while(x)
    {
        ans+=v[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(i64 i=1;i<=n;i++)
    {
        cin>>a[i];
        ind[i]=i;
    }
    sort(ind+1,ind+n+1,[](i64 x,i64 y){
        return a[x]<a[y];
    });
    sort(a+1,a+n+1);
    vector<pair<i64,i64>> vt;
    i64 d1,d2;
    vt.emplace_back(
        min(ind[1],ind[2]),
        max(ind[1],ind[2]));
    vt.emplace_back(
        min(ind[n-1],ind[n]),
        max(ind[n-1],ind[n]));

    for(i64 i=2;i<n;i++)
    {
        d1=abs(a[i]-a[i-1]);
        d2=abs(a[i+1]-a[i]);
        if(d1==d2)
        {
            vt.emplace_back(
                min(ind[i-1],ind[i]),
                max(ind[i-1],ind[i]));
            vt.emplace_back(
                min(ind[i],ind[i+1]),
                max(ind[i],ind[i+1]));
        }
        else if(d2<d1)
        {
            vt.emplace_back(
                min(ind[i],ind[i+1]),
                max(ind[i],ind[i+1]));
        }
        else
        {
            vt.emplace_back(
                min(ind[i-1],ind[i]),
                max(ind[i-1],ind[i]));
        }
    }
    sort(begin(vt),end(vt),[](auto& x,auto& y){
        return get<1>(x) < get<1>(y);
    });
    vector<tuple<i64,i64,i64>> q;
    i64 l,r;
    for(i64 i=1;i<=m;i++)
    {
        cin>>l>>r;
        q.emplace_back(l,r,i);
    }
    sort(begin(q),end(q),[](auto& x,auto& y){
        return get<1>(x)<get<1>(y);
    });
    i64 id=0;
    i64 ans=0;
    for(auto [x,y,z]:q)
    {
        while(id<vt.size()&&vt[id].second<=y)
        {
            add(vt[id].first,1);
            id++;
        }
        ans+=z*(id-query(x-1));
    }
    cout<<ans<<endl;
    
}
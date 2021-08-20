#include<bits/stdc++.h>
using namespace std;
using i64=long long;
i64 lowbit(i64 n)
{
    return n&(-n);
}
void add(i64 n,i64 d,vector<i64>& a)
{
    while(n<=2e4)
    {
        a[n]+=d;
        n+=lowbit(n);
    }
}
i64 sum(i64 n,vector<i64>& a)
{
    i64 ans=0;
    while(n)
    {
        ans+=a[n];
        n-=lowbit(n);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<i64> cnt(2e4+10),val(2e4+10);
    vector<pair<i64,i64>> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(begin(v)+1,end(v),[](auto &x,auto &y){return x.first<y.first;});
    i64 ans=0;
    for(int i=1;i<=n;i++)
    {
        auto&[vi,xi]=v[i];
        ans+=vi*(xi*sum(xi,cnt)-sum(xi,val))+
        vi*(sum(2e4,val)-sum(xi,val)-
        xi*(sum(2e4,cnt)-sum(xi,cnt)));
        add(xi,1,cnt);
        add(xi,xi,val);
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int n;
const int mod=1e8-3;
int lowbit(int x)
{
    return x&(-x);
}
long long sum(int i,vector<long long>& a)
{
    long long ans=0;
    while(i)
    {
        ans+=a[i];
        i-=lowbit(i);
    }
    return ans;
}
void update(int i,int j,vector<long long>& a)
{
    while(i<=n)
    {
        a[i]+=j;
        i+=lowbit(i);
    }
}
long long unordered_pair(vector<int>& v)
{
    vector<long long> a(n+2,0);
    long long ans=0;
    for(int i=n;i>=1;i--)
    {
        ans=(ans+sum(v[i]-1,a))%mod;
        update(v[i],1,a);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector<int> a(n+1),b(n+1),c(n+1),d(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        d[i]=i;
    }
    sort(begin(c)+1,end(c),[&](int i,int j){return a[i]<a[j];});
    sort(begin(d)+1,end(d),[&](int i,int j){return b[i]<b[j];});
    vector<int> q(n+1);
    for(int i=1;i<=n;i++)
    {
        q[c[i]]=d[i];
    }
    long long ans=unordered_pair(q);
    cout<<ans<<endl;
}
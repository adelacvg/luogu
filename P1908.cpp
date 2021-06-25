#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a(500020,0);
int lowbit(int x)
{
    return x&(-x);
}
long long sum(int i)
{
    long long ans=0;
    while(i)
    {
        ans+=a[i];
        i-=lowbit(i);
    }
    return ans;
}
void update(int i,int j)
{
    while(i<=n)
    {
        a[i]+=j;
        i+=lowbit(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> w(v);
    sort(begin(w),end(w));
    w.erase(unique(begin(w),end(w)),end(w));
    unordered_map<int,int> ma;
    for(int i=0;i<w.size();i++)
    {
        ma[w[i]]=i+1;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=i-sum(ma[v[i]]);
        update(ma[v[i]],1);
    }
    cout<<ans<<endl;
}
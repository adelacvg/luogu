#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=5e4;
vector<int> a(maxn+10,0);
vector<int> b(maxn+10,1e7);
vector<int> h(maxn+10);
int n,q;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int h)
{
    while(x<=n)
    {
        a[x]=max(a[x],h);
        b[x]=min(b[x],h);
        x+=lowbit(x);
    }
}
int query_min(int l,int r)
{
    if(l==r)
        return h[l];
    auto tr=r-lowbit(r);
    if(tr>=l)
    {
        return min(query_min(l,tr),b[r]);
    }
    else
    {
        return min(query_min(l,r-1),h[r]);
    }
}
int query_max(int l,int r)
{
    if(l==r)
        return h[l];
    auto tr=r-lowbit(r);
    if(tr>=l)
    {
        return max(query_max(l,tr),a[r]);
    }
    else
    {
        return max(query_max(l,r-1),h[r]);
    }

}

int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        add(i,h[i]);
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<query_max(l,r)-query_min(l,r)<<endl;
    }
}
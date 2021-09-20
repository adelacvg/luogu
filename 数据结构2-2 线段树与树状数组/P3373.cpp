#include<bits/stdc++.h>
using namespace std;

using i64=long long;
const int maxn=1e5+10;
int n,m;
int mod;
// vector<i64> v(maxn),seg(maxn<<2),tag(maxn<<2);
i64 v[maxn],seg[maxn<<2],tag[maxn<<2],tag2[maxn<<2];
i64 ls(i64 x)
{
    return x<<1;
}
i64 rs(i64 x)
{
    return x<<1|1;
}
void push_up(i64 x)
{
    seg[x]=(seg[ls(x)]+seg[rs(x)])%mod;
}
void build(i64 x,i64 l,i64 r)
{
    tag[x]=0;
    tag2[x]=1;
    if(l==r)
    {
        seg[x]=v[l]%mod;
        return;
    }
    i64 mid=l+((r-l)>>1);
    build(ls(x),l,mid);
    build(rs(x),mid+1,r);
    push_up(x);
}
void f(i64 x,i64 l,i64 r,i64 k)
{
    tag[x]=(tag[x]+k)%mod;
    seg[x]=(seg[x]+k*(r-l+1))%mod;
}

void push_down(i64 x,i64 l,i64 r)
{
    i64 mid=l+((r-l)>>1);
    f(ls(x),l,mid,tag[x]);
    f(rs(x),mid+1,r,tag[x]);
    tag[x]=0;
}
void f2(i64 x,i64 l,i64 r,i64 k)
{
    tag2[x]=tag2[x]*k%mod;
    tag[x]=tag[x]*k%mod;
    seg[x]=seg[x]*k%mod;
}

void push_down2(i64 x,i64 l,i64 r)
{
    i64 mid=l+((r-l)>>1);
    f2(ls(x),l,mid,tag2[x]);
    f2(rs(x),mid+1,r,tag2[x]);
    tag2[x]=1;
}
void update(i64 nl,i64 nr,i64 l,i64 r,i64 x,i64 k)
{
    if(nl<=l&&nr>=r)
    {
        seg[x]=(seg[x]+k*(r-l+1))%mod;
        tag[x]=(tag[x]+k)%mod;
        return;
    }
    push_down2(x,l,r);
    push_down(x,l,r);
    i64 mid=l+((r-l)>>1);
    if(nl<=mid)
        update(nl,nr,l,mid,ls(x),k);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(x),k);
    push_up(x);
}
void update2(i64 nl,i64 nr,i64 l,i64 r,i64 x,i64 k)
{
    if(nl<=l&&nr>=r)
    {
        seg[x]=seg[x]*k%mod;
        tag2[x]=tag2[x]*k%mod;
        tag[x]=tag[x]*k%mod;
        return;
    }
    push_down2(x,l,r);
    push_down(x,l,r);
    i64 mid=l+((r-l)>>1);
    if(nl<=mid)
        update2(nl,nr,l,mid,ls(x),k);
    if(nr>mid)
        update2(nl,nr,mid+1,r,rs(x),k);
    push_up(x);
}
i64 query(i64 q_x,i64 q_y,i64 l,i64 r,i64 x)
{
    i64 res=0;
    if(q_x<=l&&q_y>=r)
        return seg[x];
    i64 mid=l+((r-l)>>1);
    push_down2(x,l,r);
    push_down(x,l,r);
    if(q_x<=mid)
        res=(res+query(q_x,q_y,l,mid,ls(x)))%mod;
    if(q_y>mid)
        res=(res+query(q_x,q_y,mid+1,r,rs(x)))%mod;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>mod;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    build(1,1,n);
    int flag;
    int x,y,k;
    while(m--)
    {
        cin>>flag;
        if(flag==1)
        {
            cin>>x>>y>>k;
            update2(x,y,1,n,1,k);
        }
        else if(flag==2)
        {
            cin>>x>>y>>k;
            update(x,y,1,n,1,k);
        }
        else
        {
            cin>>x>>y;
            cout<<query(x,y,1,n,1)<<'\n';
        }
    }
}
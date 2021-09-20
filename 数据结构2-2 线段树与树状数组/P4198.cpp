#include<bits/stdc++.h>
using namespace std;

using i64=long long;
const int maxn=1e5+10;
int n,m;
// vector<i64> v(maxn),seg(maxn<<2),tag(maxn<<2);
double v[maxn],seg[maxn<<2];
int seg2[maxn<<2];
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
    seg[x]=max(seg[ls(x)],seg[rs(x)]);
}
int query(int l,int r,int x,double k)
{
    if(seg[x]<=k)
        return 0;
    if(v[l]>k)
        return seg2[x];
    if(l==r)
        return v[l]>k;
    // auto mid=(ls(x)+rs(x))>>1;
    i64 mid=l+((r-l)>>1);
    if(seg[ls(x)]<=k)
        return query(mid+1,r,rs(x),k);
    else
        return query(l,mid,ls(x),k)+seg2[x]-seg2[ls(x)];
}

void update(i64 nl,i64 nr,i64 l,i64 r,i64 x,i64 k)
{
    if(nl==l&&nr==r)
    {
        seg[x]=k*1.0/l;
        seg2[x]=1;
        return;
    }
    i64 mid=l+((r-l)>>1);
    if(nl<=mid)
        update(nl,nr,l,mid,ls(x),k);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(x),k);
    push_up(x);
    seg2[x]=seg2[ls(x)]+query(mid+1,r,rs(x),seg[ls(x)]);
}

int main()
{
    ifstream cin("P4198_2.in");
    ofstream cout("out.out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        v[x]=y*1.0/x;
        update(x,x,1,n,1,y);
        cout<<seg2[1]<<'\n';
    }
}
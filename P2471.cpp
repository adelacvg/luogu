#include<bits/stdc++.h>
using namespace std;

using i64=long long;
const int maxn=5e4+10;
int n,m;
i64 v[maxn],seg[maxn<<2],tag[maxn<<2];
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
void build(i64 x,i64 l,i64 r)
{
    tag[x]=0;
    if(l==r)
    {
        seg[x]=v[l];
        return;
    }
    i64 mid=l+((r-l)>>1);
    build(ls(x),l,mid);
    build(rs(x),mid+1,r);
    push_up(x);
}
i64 query(i64 q_x,i64 q_y,i64 l,i64 r,i64 x)
{
    i64 res=0;
    if(q_x<=l&&q_y>=r)
        return seg[x];
    i64 mid=l+((r-l)>>1);
    if(q_x<=mid)
        res=max(res,query(q_x,q_y,l,mid,ls(x)));
    if(q_y>mid)
        res=max(res,query(q_x,q_y,mid+1,r,rs(x)));
    return res;
}

int main()
{
    // ifstream cin("P2471_3.in");
    // ofstream cout("out.out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int year,rain;
    map<int,int> ma;

    for(int i=1;i<=n;i++)
    {
        cin>>year>>rain;
        ma[year]=i;
        v[i]=rain;
    }
    build(1,1,n);
    cin>>m;
    int y,x;
    
    while(m--)
    {
        int flag;
        cin>>y>>x;
        if(y>=x)
        {
            cout<<"false"<<'\n';
            continue;
        }
        if(!ma.count(x)&&!ma.count(y))
        {
            cout<<"maybe"<<'\n';
            continue;
        }
        auto liter=ma.lower_bound(y),riter=ma.lower_bound(x);
        if(liter==ma.end())
        {
            cout<<"maybe"<<'\n';
            continue;
        }
        int l = liter->second,r = riter==ma.end()?ma.size()+1:riter->second;
        if(!ma.count(y))
            l--;
        auto mx=l+1<=r-1?query(l+1,r-1,1,n,1):0;
        if(!ma.count(y))
            flag=mx<v[r];
        else if(!ma.count(x))
            flag=v[l]>mx;
        else
            flag=v[l]>=v[r]&&v[r]>mx;
        if(ma.count(x)&&ma.count(y)&&r-l==x-y)
        {
            if(flag)
                cout<<"true"<<'\n';
            else
                cout<<"false"<<'\n';
        }
        else
        {
            if(flag)
                cout<<"maybe"<<'\n';
            else
                cout<<"false"<<'\n';
        }


    }
}
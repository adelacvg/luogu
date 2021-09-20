#include<bits/stdc++.h>
using namespace std;

using i64=long long;
const int maxn=1e5+10;
int n,m;
i64 v[maxn],seg[maxn<<2],add_tag[maxn<<2];
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
    add_tag[x]=0;
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

void f(i64 x,i64 l,i64 r,i64 k)
{
    add_tag[x]+=k;
    seg[x]+=k;
}

void push_down(i64 x,i64 l,i64 r)
{
    i64 mid=l+((r-l)>>1);
    f(ls(x),l,mid,add_tag[x]);
    f(rs(x),mid+1,r,add_tag[x]);
    add_tag[x]=0;
}
void update(i64 nl,i64 nr,i64 l,i64 r,i64 x,i64 k)
{
    if(nl<=l&&nr>=r)
    {
        seg[x]+=k;
        add_tag[x]+=k;
        return;
    }
    push_down(x,l,r);
    i64 mid=l+((r-l)>>1);
    if(nl<=mid)
        update(nl,nr,l,mid,ls(x),k);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(x),k);
    push_up(x);
}
i64 query(i64 q_x,i64 q_y,i64 l,i64 r,i64 x)
{
    i64 res=0;
    if(q_x<=l&&q_y>=r)
        return seg[x];
    i64 mid=l+((r-l)>>1);
    push_down(x,l,r);
    if(q_x<=mid)
        res=max(res,query(q_x,q_y,l,mid,ls(x)));
    if(q_y>mid)
        res=max(res,query(q_x,q_y,mid+1,r,rs(x)));
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int w,h;
        cin>>n>>w>>h;
        vector<tuple<i64,i64,i64,i64>> segs;
        vector<i64> yv;
        for(int i=1;i<=n;i++)
        {
            i64 x,y,c;
            cin>>x>>y>>c;
            segs.emplace_back(x,y,y+h-1,c);
            segs.emplace_back(x+w-1,y,y+h-1,-c);
            yv.emplace_back(y);
            yv.emplace_back(y+h-1);
        }
        sort(begin(yv),end(yv));
        yv.erase(unique(begin(yv),end(yv)),end(yv));
        // for(auto i:yv)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        sort(begin(segs),end(segs),[](auto a,auto b)
        {
            if(get<0>(a)==get<0>(b))
                return get<3>(a) > get<3>(b);
            return get<0>(a) < get<0>(b);
        });
        // cout<<"caution:"<<get<0>(segs[0])<<
        // " "<<get<0>(segs[1])<<endl;
        // for(auto [x,yl,yr,c]:segs)
        // {
        //     cout<<x<<" "<<yl<<" "<<yr<<" "<<c<<endl;
        // }
        n=yv.size();
        build(1,1,n);
        i64 ans=0;
        for(auto [x,yl,yr,c]:segs)
        {
            i64 l=lower_bound(begin(yv),end(yv),yl)-begin(yv)+1;
            i64 r=lower_bound(begin(yv),end(yv),yr)-begin(yv)+1;
            // cout<<x<<" "<<l<<" "<<r<<" "<<c<<endl;
            update(l,r,1,n,1,c);
            ans=max(ans,seg[1]);
        }
        cout<<ans<<'\n';
    }
}
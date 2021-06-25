#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y0,y1,c;
};
vector<int> yv;

struct segtree
{
    segtree(int n):L(n<<3+1),R(n<<3+1),v(n<<3+1),len(n<<3+1){}
    vector<int> L,R,v,len;
    void init(int i,int l,int r)
    {
        L[i]=l,R[i]=r,v[i]=len[i]=0;
        // cout<<i<<" "<<l<<" "<<r<<endl;
        if(l!=r)
        {
            int mid=(l+r)>>1;
            init(i<<1,l,mid);
            init(i<<1|1,mid+1,r);
        }
    }
    void add(int i,int l,int r,int c)
    {
        if(r<L[i]||R[i]<l)
            return;
        if(l<=L[i]&&R[i]<=r)
            v[i]+=c;
        else
        {
            add(i<<1,l,r,c);
            add(i<<1|1,l,r,c);
        }
        if(v[i])
        {
            len[i]=yv[R[i]+1]-yv[L[i]];
        }
        else
        {
            len[i]=len[i<<1]+len[i<<1|1];
        }
    }
};

int main()
{
    // ifstream cin("P1884_5.in");
    int n;
    cin>>n;
    unordered_map<int,int> ma;
    vector<node> v(2*n+1);
    int x0,y0,x1,y1;
    yv.emplace_back(0);
    for(int i=1;i<=n;i++)
    {
        cin>>x0>>y0>>x1>>y1;
        v[i]=node{x0,y1,y0,1};
        v[i+n]=node{x1,y1,y0,-1};
        yv.emplace_back(y0);
        yv.emplace_back(y1);
    }
    sort(begin(yv)+1,end(yv));
    yv.erase(unique(begin(yv)+1,end(yv)),end(yv));
    for(int i=1;i<yv.size();i++)
    {
        ma[yv[i]]=i;
    }
    sort(begin(v)+1,end(v),[](auto& a,auto& b){
        return a.x<b.x;
        });
    long long ans=0;
    segtree seg(n);
    seg.init(1,1,(n<<=1));
    for(int i=1;i<n;i++)
    {
        seg.add(1,ma[v[i].y0],ma[v[i].y1]-1,v[i].c);
        ans+=(long long)seg.len[1]*(v[i+1].x-v[i].x);
    }
    cout<<ans<<endl;
}
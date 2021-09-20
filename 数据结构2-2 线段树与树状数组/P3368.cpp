#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;
int n,m,tree[maxn];
int a[maxn],b[maxn];

int lowbit(int x)
{
    return x&(~x+1);
}
void add(int x,int k)
{
    while(x<=n)
    {
        tree[x]+=k;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int sum=0;
    while(x)
    {
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int x,y,k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]-a[i-1];
        add(i,b[i]);
    }
    int flag;
    while(m--)
    {
        cin>>flag;
        if(flag==1)
        {
            cin>>x>>y>>k;
            add(x,k);
            add(y+1,-k);
        }
        else
        {
            cin>>x;
            cout<<query(x)<<'\n';
        }
    }
}
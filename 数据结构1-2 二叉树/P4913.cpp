#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> son(1000010);
vector<int> fa(1000010);
int deep(int root)
{
    auto &[l,r]=son[root];
    int h=1,lh=0,rh=0;
    if(l)
        lh=deep(l);
    if(r)
        rh=deep(r);
    return h+max(lh,rh);
}

int main()
{
    int n;
    cin>>n;
    int l,r;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        fa[l]=i;
        son[i]=make_pair(l,r);
    }
    cout<<deep(1);
}
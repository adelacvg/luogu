#include<bits/stdc++.h>
using namespace std;
void deep(vector<vector<int>>& v,
vector<int>& dep,int root)
{
    for(auto i:v[root])
    {
        dep[i]=dep[root]+1;
        deep(v,dep,i);
    }
}


int main()
{
    int n;
    cin>>n;
    int root=1;
    vector<vector<int>> v(n+1,vector<int>{});
    vector<int> fa(n+1);
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        v[x].emplace_back(y);
        fa[y]=x;
    }
    vector<int> dep(n+1,0);
    deep(v,dep,root);
    int d=1,w=1;
    map<int,int> m;
    for(int i=1;i<=n;i++)
    {
        d=max(d,dep[i]+1);
        m[dep[i]]++;
        w=max(w,m[dep[i]]);
    }
    cout<<d<<endl;
    cout<<w<<endl;
    int uu,vv;
    cin>>uu>>vv;
    if(uu==vv)
    {
        cout<<0;
        return 0;
    }
    int dis1=0,dis2=0;
    while(fa[uu]!=fa[vv])
    {
        if(fa[uu]==vv)
        {
            cout<<(dis1+1)*2<<endl;
            return 0;
        }
        else if(fa[vv]==uu)
        {
            cout<<dis2+1<<endl;
            return 0;
        }
        else if(dep[uu]>dep[vv])
        {
            dis1++;
            uu=fa[uu];
        }
        else if(dep[vv]>dep[uu])
        {
            dis2++;
            vv=fa[vv];
        }
        else if(dep[uu]==dep[vv]&&fa[uu]!=fa[vv])
        {
            dis1++;
            dis2++;
            uu=fa[uu];
            vv=fa[vv];
        }
    }
    cout<<2*(dis1+1)+dis2+1<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    list<int> v{1};
    vector<decltype(begin(v))> pos(n+1);
    vector<bool> erase(n+1,0);
    pos[1]=begin(v);
    for(int i=2;i<=n;i++)
    {
        int k,p;
        cin>>k>>p;
        if(p==0)
            pos[i]=v.insert(pos[k],i);
        else
            pos[i]=v.insert(next(pos[k]),i);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        if(!erase[x])
        {
            erase[x]=1;
            v.erase(pos[x]);
        }
    }
    for(auto i:v)
    {
        if(!erase[i])
            cout<<i<<" ";
    }
}
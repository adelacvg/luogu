#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,m;
    cin>>l>>m;
    vector<int> a(l+10,0);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u]++;
        a[v+1]--;
    }
    int ans=l+1;
    int now=0;
    for(int i=0;i<=l;i++)
    {
        now+=a[i];
        if(now)
            ans--;
    }
    cout<<ans<<endl;
}
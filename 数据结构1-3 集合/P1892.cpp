#include<bits/stdc++.h>
using namespace std;
int find_fa(int x,vector<int>& fa)
{
    return x==fa[x]?x:fa[x]=find_fa(fa[x],fa);
}

int main()
{
    int n;
    int m;
    cin>>n>>m;
    vector<int> fa(n+1);
    vector<int> en(n+1,0);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    while(m--)
    {
        char opt;
        int p,q;
        cin>>opt>>p>>q;
        if(opt=='E')
        {
            if(!en[p])
                en[p]=q;
            else
                fa[find_fa(q,fa)]=find_fa(en[p],fa);
            if(!en[q])
                en[q]=p;
            else
                fa[find_fa(p,fa)]=find_fa(en[q],fa);
        }
        else
        {
            fa[find_fa(p,fa)]=find_fa(q,fa);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==i)
            ans++;
    }
    cout<<ans<<endl;
}
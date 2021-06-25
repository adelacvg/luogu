#include<bits/stdc++.h>
using namespace std;
int find_fa(int x,vector<int>& fa)
{
    return fa[x]=(fa[x]==x?x:find_fa(fa[x],fa));
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> fa(n+1);
    vector<int> en(n+1,0);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    vector<tuple<int,int,int>> v;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.emplace_back(make_tuple(a,b,c));
    }
    sort(begin(v),end(v),[](auto& a,auto& b){
        return get<2>(a)>get<2>(b);
    });
    int flag=0;
    for(auto& [a,b,c]:v)
    {
        if(find_fa(a,fa)==find_fa(b,fa))
        {
            flag=1;
            cout<<c<<endl;
            break;
        }
        else
        {
            if(!en[a])
                en[a]=b;
            else
            {
                fa[find_fa(b,fa)]=find_fa(en[a],fa);
            }
            if(!en[b])
                en[b]=a;
            else
            {
                fa[find_fa(a,fa)]=find_fa(en[b],fa);
            }
        }
    }
    if(!flag)
        cout<<0<<endl;
}
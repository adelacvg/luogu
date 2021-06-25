#include<bits/stdc++.h>
using namespace std;
int find_fa(int x,map<int,int>& fa)
{
    return x==fa[x]?x:fa[x]=find_fa(fa[x],fa);
}

int main()
{
    // ifstream cin("P1955_2.in");
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int> fa;
        int flag=1;
        vector<tuple<int,int,int>> v1,v0;
        int x,y,e;
        while(n--)
        {
            cin>>x>>y>>e;
            fa[x]=x;
            fa[y]=y;
            if(e)
                v1.emplace_back(make_tuple(x,y,e));
            else
                v0.emplace_back(make_tuple(x,y,e));
        }
        for(auto &[i,j,e]:v1)
        {
            fa[find_fa(i,fa)]=find_fa(j,fa);
        }
        for(auto &[i,j,e]:v0)
        {
            if(find_fa(i,fa)==find_fa(j,fa))
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(begin(v),end(v),[](auto a,auto b){
        return a.first<b.first;
    });
    int ans=0;
    for(auto& [i,j]:v)
    {
        if(n>j)
        {
            ans+=i*j;
            n-=j;
        }
        else
        {
            ans+=n*i;
            break;
        }
    }
    cout<<ans<<endl;
}
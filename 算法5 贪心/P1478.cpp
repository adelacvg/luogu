#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    cin>>n>>s;
    int a,b;
    cin>>a>>b;
    int x,y;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x<=a+b)
            v.emplace_back(make_pair(x,y));
    }
    sort(begin(v),end(v),[](auto& a,auto& b){
        return a.second<b.second;
    });
    int ans=0;
    for(auto& [i,j]:v)
    {
        if(j<=s)
        {
            ans++;
            s-=j;
        }
        else
            break;
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(begin(v),end(v),[](auto x,auto y){
        return x.second*y.first>x.first*y.second;
    });
    double ans=0;
    for(auto [i,j]:v)
    {
        if(t>=i)
        {
            ans+=j;
            t-=i;
        }
        else if(t)
        {
            ans+=j*1.0/i*t;
            t=0;
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
}
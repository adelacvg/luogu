#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(begin(v),end(v),[](auto& x,auto& y){
        return x.first*x.second<y.second*y.first;
    });
    long long ans=1;
    for(auto& [i,j]:v)
    {
        ans*=i;
    }
    ans/=v[n-1].first;
    ans/=v[n-1].second;
    cout<<ans<<endl;
}
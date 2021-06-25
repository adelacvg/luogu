#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(begin(v),end(v),[](auto& a,auto& b){
        return a.second==b.second?a.first>b.first:a.second<b.second;
    });
    int ans=0;
    int r=0;
    for(auto&[i,j]:v)
    {
        if(i>=r)
        {
            ans++;
            r=j;
        }
    }
    cout<<ans<<endl;
}
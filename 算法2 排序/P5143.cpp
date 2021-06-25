#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<tuple<int,int,int>> v;
    int x,y,z;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        v.emplace_back(make_tuple(x,y,z));
    }
    sort(begin(v),end(v),[](auto &i,auto &j){
        auto &[x1,y1,z1]=i;
        auto &[x2,y2,z2]=j;
        return z1<z2;
    });
    double ans=0;
    for(int i=0;i<n-1;i++)
    {
        auto &[x1,y1,z1]=v[i];
        auto &[x2,y2,z2]=v[i+1];
        ans+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
    }
    cout<<fixed<<setprecision(3)<<ans;
}
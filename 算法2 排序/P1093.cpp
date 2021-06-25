#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x,y,z;
    vector<tuple<int,int,int,int>> v;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        v.push_back(make_tuple(x,y,z,i));
    }
    sort(begin(v),end(v),[](auto &i,auto &j){
        auto& [x1,y1,z1,id1]=i;
        auto& [x2,y2,z2,id2]=j;
        if(x1+y1+z1==x2+y2+z2)
        {
            if(x1==x2)
                return id1<id2;
            else
                return x1>x2;
        }
        else
            return x1+y1+z1>x2+y2+z2;
    });
    for(int i=0;i<5;i++)
    {
        auto&[x,y,z,id]=v[i];
        cout<<id<<" "<<x+y+z<<endl;
    }
}
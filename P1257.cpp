#include<bits/stdc++.h>
using namespace std;

int main()
{
    double cos_theta=cos(1);
    double sin_theta=sin(1);
    int n;
    cin>>n;
    auto dis=[](auto& p1,auto& p2){
        auto&[x1,y1,x,y]=p1;
        auto&[x2,y2,xx,yy]=p2;
        return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
    };
    vector<pair<double,double>> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;
    vector<tuple<double,double,double,double>> w;
    transform(begin(v),end(v),back_inserter(w),
    [&](auto& p)->tuple<double,double,double,double>{
        auto& [x,y]=p;
        return {x*cos_theta-y*sin_theta,x*sin_theta+y*sin_theta,x,y};
        });
    double ans=INT64_MAX;
    sort(begin(w),end(w),[](auto& a,auto& b){return get<0>(a)<get<0>(b);});
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=4&&j+i<n;j++)
        {
            ans=min(ans,dis(w[i],w[i+j]));
        }
    }
    cout<<fixed<<setprecision(4)<<ans<<endl;
}
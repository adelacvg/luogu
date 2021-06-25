#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<double> x,y;
    long double a,b;
    for(int i=0;i<3;i++)
    {
        cin>>a>>b;
        x.emplace_back(a);
        y.emplace_back(b);
    }
    long double ans=0;
    for(int i=0;i<3;i++)
    {
        for(int j=i+1;j<3;j++)
        {
            ans+=sqrt((x[i]-x[j])*(x[i]-x[j])+
            (y[i]-y[j])*(y[i]-y[j]));
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
}
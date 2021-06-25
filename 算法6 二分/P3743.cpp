#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;
    vector<int> a(n),b(n);
    double mx=0;
    long long sm=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        mx=max(mx,b[i]*1.0/a[i]);
        sm+=a[i];
    }
    if(sm<=p)
        cout<<-1<<endl;
    else
    {
        double l=0,r=3e9;
        while(l<=r)
        {
            double mid=l+(r-l)/2.0;
            double t=0;
            for(int i=0;i<n;i++)
            {
                t+=max(0.0,-(b[i]-a[i]*mid)/p);
            }
            if(t<mid)
            {
                l=mid+1e-6;
            }
            else if(t>mid)
            {
                r=mid-1e-6;
            }
            else
            {
                l=mid;
                break;
            }
        }
        cout<<fixed<<setprecision(10)<<l<<endl;
    }

}
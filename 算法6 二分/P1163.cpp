#include<bits/stdc++.h>
using namespace std;

int main()
{
    double debt,eve_mon,mon;
    cin>>debt>>eve_mon>>mon;
    double l=0,r=5;
    while(l<=r)
    {
        double mid=l+(r-l)/2.0;
        double t=debt;
        for(int i=0;i<mon;i++)
        {
            t=t*(1+mid)-eve_mon;
        }
        if(t<0)
        {
            l=mid+0.000001;
        }
        else if(t>0)
        {
            r=mid-0.000001;
        }
        else
        {
            l=mid;
            break;
        }
    }
    cout<<fixed<<setprecision(1)<<round(l*1000)/10.0<<endl;
}
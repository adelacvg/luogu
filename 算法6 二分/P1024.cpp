#include<bits/stdc++.h>
using namespace std;
double f(double a,double b,double c,double d,double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double t;
    vector<double> ans;
    for(double i=-100.0;i<=99.0;i++)
    {
        double y1=f(a,b,c,d,i);
        double y2=f(a,b,c,d,i+1);
        if(y1*y2<=0)
        {
            double l=i,r=i+1,mid;
            while(r>=l)
            {
                mid=l+(r-l)/2;
                t=f(a,b,c,d,mid);
                if(t>0)
                {
                    if(y1>=y2)
                        l=mid+0.0001;
                    else
                        r=mid-0.0001;
                }
                else if(t<0)
                {
                    if(y1>=y2)
                        r=mid-0.0001;
                    else
                        l=mid+0.0001;
                }
                else
                {
                    ans.push_back(round(mid*100)/100.0);
                    break;
                }
            }
            ans.push_back(round(mid*100)/100.0);
        }
    }
    ans.erase(unique(begin(ans),end(ans)),end(ans));
    for(auto i:ans)
        cout<<fixed<<setprecision(2)
        <<i<<" ";

}
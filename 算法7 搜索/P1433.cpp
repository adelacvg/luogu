#include<bits/stdc++.h>
using namespace std;
vector<vector<double>> dp(20,vector<double>((1<<17),((1<<20)-1)));
double dis(pair<double,double> a,pair<double,double> b)
{
    double t1=a.first-b.first;
    double t2=a.second-b.second;
    return sqrt(t1*t1+t2*t2);
}
int main()
{
    int n;
    cin>>n;
    vector<pair<double,double>> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;
    for(int s=1;s<=(1<<n)-1;s++)
    {
        for(int i=0;i<n;i++)
        {
            if((s&(1<<i))==0)
            {
                continue;
            }
            if((s==(1<<i)))
            {
                dp[i][s]=0; continue;
            }
            for(int j=0;j<n;j++)
            {
                if((s&(1<<j))==0||i==j) continue;
                dp[i][s]=min(dp[i][s],dp[j][s-(1<<i)]+dis(v[i],v[j]));
            }
        }
    }
    double ans=-1;
    for(int i=0;i<n;i++)
    {
        double t=dp[i][(1<<n)-1]+dis(v[i],make_pair(0.0,0.0));
        if(ans==-1||ans>t) ans=t;
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
}
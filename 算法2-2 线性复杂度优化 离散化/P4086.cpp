#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n+2);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    vector<int> mn(n+2);
    mn[n+1]=INT_MAX;
    for(int i=n;i>=1;i--)
    {
        mn[i]=min(mn[i+1],v[i]);
    }
    vector<int> presum(n+1);
    for(int i=1;i<=n;i++)
    {
        presum[i]=presum[i-1]+v[i];
    }
    double ans=0;
    mn[n+1]=0;
    for(int i=1;i<n;i++)
    {
        auto t=presum[n]-presum[i]-mn[i+1];
        if(1.0*t/(n-i-1)>ans)
        {
            ans=1.0*t/(n-i-1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        auto t=presum[n]-presum[i]-mn[i+1];
        if(1.0*t/(n-i-1)==ans)
        {
            cout<<i<<'\n';
        }
    }

}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // ifstream cin("P1182_4.in");
    long long n,m;
    cin>>n>>m;
    vector<long long> v(n);
    long long sum=0;
    long long mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
        mx=max(mx,v[i]);
    }
    long long l=mx,r=sum;
    while(l<=r)
    {
        long long mid=l+(r-l)/2;
        long long t=0;
        long long subsum=0;
        for(int i=0;i<n;i++)
        {
            if(subsum+v[i]<=mid)
                subsum+=v[i];
            else
            {
                subsum=v[i];
                t++;
            }
        }
        t++;
        if(t<m)
        {
            r=mid-1;
        }
        else if(t>m)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<l<<endl;
}
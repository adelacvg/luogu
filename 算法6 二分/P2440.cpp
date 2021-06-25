#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    long long sum=0;
    vector<long long> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    long long l=1,r=sum/k;
    while(l<=r)
    {
        long long mid=l+(r-l)/2;
        long long t=0;
        for(auto i:v)
        {
            t+=i/mid;
        }
        if(t>k)
        {
            l=mid+1;
        }
        else if(t<k)
        {
            r=mid-1;
        }
        else
        {
            r=mid;
            break;
        }
    }
    while(1)
    {
        long long t=0;
        for(auto i:v)
        {
            t+=i/(r+1);
        }
        if(t==k)
            r++;
        else
            break;
    }
    cout<<r<<endl;
}
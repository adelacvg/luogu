#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
    vector<int> v(n);
    int maxh=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        maxh=max(maxh,v[i]);
    }
    sort(begin(v),end(v));
    long long l=0,r=maxh,mid;
    long long sum;
    while(l<=r)
    {
        mid=l+((r-l)>>1);
        sum=0;
        for(int i=0;i<n;i++)
            sum+=max(0ll,v[i]-mid);
        if(sum>m)
            l=mid+1;
        else if(sum<m)
            r=mid-1;
        else
        {
            r=mid;
            break;
        }
    }
    cout<<r<<endl;
}
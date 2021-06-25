#include<bits/stdc++.h>
using namespace std;

int main()
{
    int len,n,k;
    cin>>len>>n>>k;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int l=1,r=len;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        int t=0;
        for(int i=1;i<n;i++)
        {
            if((v[i]-v[i-1])%mid==0)
            {
                t+=(v[i]-v[i-1])/mid-1;
            }
            else
            {
                t+=(v[i]-v[i-1])/mid;
            }
        }
        if(t<k)
        {
            r=mid-1;
        }
        else if(t>k)
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
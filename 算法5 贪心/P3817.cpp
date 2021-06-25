#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    long long ans=0;
    int t=0;
    for(int i=1;i<n;i++)
    {
        t=v[i];
        v[i]=min(v[i],max(0,x-v[i-1]));
        ans+=t-v[i];
    }
    if(n==1)
        ans=max(0,v[0]-x);
    else
        ans+=max(0,v[0]+v[1]-x);
    cout<<ans<<endl;
}
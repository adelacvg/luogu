#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long sum=0;
    cin>>n;
    int x;
    long long ans=INT64_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(sum<0)
            sum=x;
        else
            sum+=x;
        ans=max(sum,ans);
    }
    cout<<ans<<endl;
}
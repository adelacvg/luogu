#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unsigned long long ans=0;
    for(int i=1,j;i<=n;i=j+1)
    {
        j=n/(n/i);
        ans+=n/j*(j-i+1);
    }
    cout<<ans<<endl;
}
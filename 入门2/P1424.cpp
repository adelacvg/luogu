#include<bits/stdc++.h>
using namespace std;
int a[15]{0,1,1,1,1,1,0,0,1,1,1,1,1,0,0};
int main()
{
    int x,n;
    cin>>x>>n;
    int ans=0;
    ans+=250*(n/7)*5;
    for(int i=x;i<=x+n%7-1;i++)
    {
        ans+=a[i]*250;
    }
    cout<<ans<<endl;
    return 0;
}
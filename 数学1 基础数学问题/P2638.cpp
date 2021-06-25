#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;
i64 nCm(i64 n,i64 m)
{
    i64 ans=1;
    for(i64 i=n,j=1;j<=m;i--,j++)
    {
        ans=ans*i/j;
    }
    return ans;
}

int main()
{
    i64 ans=0;
    i64 n,a,b;
    cin>>n>>a>>b;
    for(i64 i=0;i<=a;i++)
    {
        for(i64 j=0;j<=b;j++)
        {
            ans+=nCm(i+n-1,n-1)*nCm(j+n-1,n-1);
        }
    }
    cout<<ans<<endl;
}
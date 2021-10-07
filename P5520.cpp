#include<bits/stdc++.h>
using namespace std;

using i64=unsigned long long;
i64 mod;

i64 nAm(i64 n,i64 m)
{
    if(n<m)
        return 0;
    int ans=1;
    for(int i=1;i<=m;i++)
    {
        ans=(ans*(n-m+i))%mod;
    }
    return ans;
}

int main()
{
    i64 type,n,m;
    cin>>type>>n>>m>>mod;
    cout<<nAm(n-m+1,m)<<'\n';
}
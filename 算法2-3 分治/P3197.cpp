#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;
constexpr i64 mod=1e5+3;

i64 qpow(i64 a,i64 b)
{
    i64 ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    i64 m,n;
    cin>>m>>n;
    i64 ans=(qpow(m,n)-m*qpow(m-1,n-1)%mod+mod)%mod;
    cout<<ans<<endl;
}
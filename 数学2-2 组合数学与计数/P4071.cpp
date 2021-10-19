#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;
constexpr const i64 mod=1e9+7;
constexpr const i64 maxn=1e6+10;
i64 d[maxn],fac[maxn],inv[maxn];

i64 qpow(i64 n,i64 m)
{
    i64 ans=1;
    while(m)
    {
        if(m&1)
            ans=(ans*n)%mod;
        n=(n*n)%mod;
        m>>=1;
    }
    return ans;
}

i64 invf(i64 x)
{
    return qpow(x,mod-2);
}

i64 nCm(i64 n,i64 m)
{
    return (fac[n]*invf(fac[m]*fac[n-m]%mod))%mod;
}

i64 lucas(i64 n,i64 m)
{
    if(m==0)
        return 1;
    return nCm(n%mod,m%mod)*lucas(n/mod,m/mod)%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 t;
    cin>>t;
    d[0]=1;
    fac[0]=1;
    for(i64 i=1;i<=maxn;i++)
    {
        d[i]=(i-1)*(d[i-1]+d[i-2])%mod;
        fac[i]=fac[i-1]*i%mod;
    }
    inv[1]=1;
    for(int i=2;i<=maxn;i++)
    {
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
    while(t--)
    {
        i64 n,m;
        cin>>n>>m;
        cout<<lucas(n,m)*d[n-m]%mod<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;
vector<i64> prime;
vector<bool> flag(1e6+10);
void euler_sieve(int n)
{
    for(auto i=2ull;i<=n;i++)
    {
        if(!flag[i])
            prime.emplace_back(i);
        for(int j=0;j<prime.size()&&i*prime[j]<=n;j++)
        {
            flag[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
int main()
{
    euler_sieve(1000000);
    vector<i64> v(1000010);
    vector<i64> phi(1000010);
    i64 l,r;
    cin>>l>>r;
    for(auto i=l;i<=r;i++)
    {
        v[i-l]=i;
        phi[i-l]=i;
    }
    for(int i=0;i<prime.size()&&prime[i]*prime[i]<=r;i++)
    {
        auto p=prime[i];
        auto ll=l;
        if(l%p)
        {
            ll=(l/p+1)*p;
        }
        for(auto j=ll;j<=r;j+=p)
        {
            phi[j-l]=phi[j-l]/p*(p-1);
            while(v[j-l]%p==0)
            {
                v[j-l]/=p;
            }
        }
    }
    i64 mod=666623333;
    i64 ans=0;
    for(auto i=l;i<=r;i++)
    {
        if(v[i-l]!=1)
        {
            phi[i-l]=phi[i-l]/v[i-l]*(v[i-l]-1);
        }
        ans=(ans+i-phi[i-l])%mod;
    }
    cout<<ans<<endl;
}
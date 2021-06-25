#include<bits/stdc++.h>
using namespace std;
using i64= long long;

int mod=9901;
vector<i64> prime;
vector<bool> flag(1e4+10,0);
void euler_sieve(i64 n)
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
    euler_sieve(1e4);
    i64 a,b;
    cin>>a>>b;
    if(a==0)
    {
        cout<<0<<endl;
        return 0;
    }
    i64 ans=1;
    for(auto p:prime)
    {
        if(p*p>a)
            break;
        if(a%p==0)
        {
            int k=0;
            while(a%p==0)
            {
                a/=p;
                k++;
            }
            if((p-1)%mod==0)
                ans=ans*(k*b+1)%mod;
            else
                ans=(ans*(qpow(p%mod,k*b+1)-1)%mod*qpow((p-1)%mod,mod-2))%mod;
        }
    }
    if(a!=1)
    {
        if((a-1)%mod==0)
            ans=ans*(b+1)%mod;
        else
            ans=(ans*(qpow(a%mod,b+1)-1)%mod*qpow((a-1)%mod,mod-2))%mod;
    }
    cout<<(ans%mod+mod)%mod<<endl;
}
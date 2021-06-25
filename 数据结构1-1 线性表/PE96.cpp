#include<bits/stdc++.h>
using namespace std;
vector<bool> f(10000010,0);
vector<int> prime;
void sieve(long long n)
{
    for(long long i=2;i<=n;i++)
    {
        if(!f[i])
            prime.emplace_back(i);
        for(long long j=i*i;j<=n;j+=i)
        {
            f[j]=1;
        }
    }
}
long long phi(long long n)
{
    for(int i=0;i<prime.size();i++)
    {
        if(prime[i]>n)
            break;
        if(n%prime[i]==0)
        {
            n=n*(prime[i]-1)/prime[i];
        }
    }
    return n;
}
int main()
{
    long long n;
    cin>>n;
    sieve(10000000);
    long long tn=1;
    double ans=1;
    for(int i=0;i<prime.size();i++)
    {
        tn=tn*prime[i];
        if(tn>n)
            break;
        ans=min(ans,phi(tn)*1.0/tn);
    }
    cout<<fixed<<setw(6)<<ans<<endl;
}
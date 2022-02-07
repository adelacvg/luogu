#include<bits/stdc++.h>
using namespace std;
using i64=long long;
i64 phi[40040];
i64 flag[40040];
vector<i64> prime;

void sieve(int n)
{
    phi[1]=1;
    phi[2]=1;
    phi[3]=2;
    for(int i=2;i<=n;i++)
    {
        if(!flag[i])
        {
            prime.emplace_back(i);
            phi[i]=i-1;
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=n;j++)
        {
            flag[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}

//2*sum1~(n-1) phi(i) +1
//phi(i*prime)=phi(i)*(prime-1) prime!|i
//             phi(i)*prime prime|i
int main()
{
    int n;
    cin>>n;
    if(n==1)
        cout<<0<<'\n';
    else
    {
        sieve(n);
        i64 sm=0;
        for(int i=1;i<n;i++)
        {
            sm+=phi[i];
        }
        cout<<2*sm+1<<'\n';
    }
}
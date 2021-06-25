#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long nCr(long long n,long long r)
{
    if(r>n)return 0;
    if(r*2>n)r=n-r;
    if(r==0)return 1;
    long long res=n;
    for(int i=2;i<=r;i++)
    {
        res=res*(n-i+1)%mod;
        res/=i;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int t;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        m[t]++;
    }
    long long ans=0;
    for(auto [i,j]:m)
    {
        if(j>=2)
        {
            for(auto[u,v]:m)
            {
                if(u>i-u)break;
                if(u==i-u&&v>=2)
                {
                    ans=(ans+nCr(j,2)%mod*
                    nCr(v,2)%mod)%mod;
                }
                else if(u!=i-u&&m[u]&&m[i-u])
                {
                    ans=(ans+nCr(j,2)%mod*
                    nCr(v,1)%mod*
                    nCr(m[i-u],1)%mod)%mod;
                }
            }
        }
    }
    cout<<ans<<endl;
}
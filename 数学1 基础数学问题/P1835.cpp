#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;
vector<int> prime{2,3,5,7};
i64 qpow(i64 a,i64 b,i64 mod)
{
    i64 ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
bool millerrobin(i64 n)
{
    if(n>3&&n%2==0)
        return false;
    else if(n<=3)
        return !(n==1);
    i64 a=n-1,b=0;
    while(a%2==0)
    {
        a>>=1;
        ++b;
    }
    for(auto p:prime)
    {
        if(p>=n)
            break;
        auto v=qpow(p,a,n);
        if(v==1||v==n-1)
            continue;
        int j;
        for(j=0;j<b;j++)
        {
            v=v*v%n;
            if(v==n-1)
                break;
        }
        if(j>=b)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    i64 l,r;
    cin>>l>>r;
    int flag=0;
    int ans=0;
    for(i64 i=l;i<=r;i++)
    {
        flag=1;
        for(auto p:prime)
        {
            if(p>=i)
                break;
            if(i%p==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            if(millerrobin(i))
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
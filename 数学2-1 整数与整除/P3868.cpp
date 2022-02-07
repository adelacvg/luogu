#include<bits/stdc++.h>
using namespace std;
using i64=long long;
i64 a[20],b[20];

template<class T>
void exgcd(T a,T b,T& x,T& y)
{
    if(b==0)
    {
        y=0;
        x=1;
        return;
    }
    exgcd(b,a%b,x,y);
    auto t=x;
    x=y;
    y=t-a/b*y;
    return;
}

template<class T>
auto qmul(T a,T b,T mod)
{
    T ans=0;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%mod;
        }
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    //M=b1*b2...*bn
    //Mi=M/bi
    //x = sum(ai*Mi*Mi^-1 mod mi)
    //crt(chinese remainder theorem)
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    i64 M=1;
    for(int i=1;i<=n;i++)
        M*=b[i];
    i64 ans=0;
    for(int i=1;i<=n;i++)
    {
        i64 Mi=M/b[i];
        i64 x,y;
        exgcd(b[i],Mi,x,y);
        // ans=(ans+y*Mi*a[i])%M;
        ans=(ans+qmul(qmul(y,Mi,M),(a[i]+M)%M,M)+M)%M;
    }
    if(ans<0)
        ans+=M;
    cout<<ans<<'\n';
}
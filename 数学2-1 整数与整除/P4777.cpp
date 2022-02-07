#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=100010;
i64 a[N],b[N];

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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>b[i]>>a[i];
    i64 ka=a[1],kb=b[1];
    for(int i=2;i<=n;i++)
    {
        i64 ta=a[i],tb=b[i];
        i64 x,y;
        i64 tgcd=gcd(tb,kb);
        exgcd(tb/tgcd,kb/tgcd,x,y);
        i64 tlcm=tb/tgcd*kb;
        x=(x%(kb/tgcd)+kb/tgcd)%(kb/tgcd);
        // ka=((ka-ta)/tgcd*x*tb+ta+tlcm)%tlcm;
        ka = (qmul(qmul((ka-ta)/tgcd,x,tlcm),tb,tlcm)+ta+tlcm)%tlcm;
        kb=tlcm;
    }
    cout<<ka<<endl;
}
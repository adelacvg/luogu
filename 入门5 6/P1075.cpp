#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long mx;

inline ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (__int128_t)res*x % p;
        y = y>>1;
        x = (__int128_t)x*x % p;
    }
    return res;
}
inline bool miillerTest(ll d, ll n)
{
    ll a = 2 + rand() % (n - 4);
    ll x = power(a, d, n);
    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        x = (__int128_t)x*x% n;
        d*= 2;
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}
inline bool isPrime(ll n, ll k)
{
    if(n==46856248255981ll || n<2)
        return false;
    if(n==2 || n==3 || n==7 || n==61 || n==24251)
        return true;
    if (n <= 1 || n == 4)  return false;
    if (n <= 3|| n==24251) return true;
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (ll i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;
    return true;
}
inline ll PollardRho(long long x)
{
    long long a=0,b=0,c=1ll*rand()%(x-1)+1;
    int stp=0,goal=1;
    long long val=1;
    for(goal=1;;goal<<=1,a=b,val=1)
    {
        for(stp=1;stp<=goal;++stp)
        {
            b=((__int128_t)b*b+c)%x;
            val=(__int128_t)val*abs(b-a)%x;
            if((stp%127)==0)
            {
                ll d=__gcd(val,x);
                if(d>1)
                    return d;
            }
        }
        ll d=__gcd(val,x);
        if(d>1)
            return d;
    }
}
inline void f(long long n)
{
    if(n<=mx || n<2)
        return;
    if(isPrime(n,2))
    {
        mx=max(mx,n);
        return;
    }
    long long p=n;
    while(p>=n)
        p=PollardRho(n);
    while((n%p)==0)
        n/=p;
    f(n),f(p);
}

int main()
{
    int n;
    cin>>n;
    mx=1;
    f(n);
    cout<<mx<<endl;
}
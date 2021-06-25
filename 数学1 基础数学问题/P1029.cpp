#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;

int main()
{
    i64 p,q;
    cin>>p>>q;
    int ans=0;
    i64 mul=p*q;
    for(i64 i=p;i<=q;i++)
    {
        if(mul%i)continue;
        auto j=mul/i;
        if(j<i)
            break;
        if(gcd(i,j)==p)
        {
            if(i<j)
                ans+=2;
            else
                ans++;
        }
    }
    cout<<ans<<endl;
}
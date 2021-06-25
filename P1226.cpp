#include<bits/stdc++.h>
using namespace std;

using i64 = unsigned long long;

int main()
{
    i64 a,b,p;
    cin>>a>>b>>p;
    cout<<a<<"^"<<b<<" mod "<<p<<"=";
    i64 ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b>>=1;
    }
    cout<<ans%p<<endl;
}
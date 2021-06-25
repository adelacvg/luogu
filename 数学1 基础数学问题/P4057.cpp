#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;

int main()
{
    i64 a,b,c;
    cin>>a>>b>>c;
    auto t=a*b/gcd(a,b);
    auto ans=t*c/gcd(t,c);
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n;
    cin>>n;
    while(n--)
    {
        i64 l,r;
        cin>>l>>r;
        auto ans = (((l+r)%9)*((r-l+1)%9)*32)%9;
        cout<<ans<<'\n';
    }
}
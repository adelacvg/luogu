#include<bits/stdc++.h>
using namespace std;

constexpr const int N=3e6+10;
long long inv[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,p;
    cin>>n>>p;
    inv[1]=1;
    for(long long i=2;i<=n;i++)
    {
        inv[i]=(p-p/i)*inv[p%i]%p;
    }
    for(long long i=1;i<=n;i++)
    {
        cout<<inv[i]<<'\n';
    }
}
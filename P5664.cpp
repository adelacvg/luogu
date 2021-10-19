#include<bits/stdc++.h>
using namespace std;
using i64=long long;

i64 mod=998244353;

i64 a[110][2020];
i64 f[110][2020],g[110][2020];
i64 s[110];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        i64 sm=0;
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            sm=(sm+a[i][j])%mod;
        }
        s[i]=sm;
    }
    for(int i=0;i<=n;i++)
        g[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            g[i][j]=(g[i-1][j]+s[i]*g[i-1][j-1])%mod;
        }
    }
    i64 ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+g[n][i])%mod;
    for(int col=1;col<=m;col++)
    {
        memset(f,0,sizeof(f));
        f[0][n]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=n-i;j<=n+i;j++)
            {
                f[i][j]=(f[i-1][j]+a[i][col]*f[i-1][j-1]+(s[i]-a[i][col])*f[i-1][j+1])%mod;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=(ans-f[n][n+i]+mod)%mod;
        }
    }
    cout<<ans<<endl;
}
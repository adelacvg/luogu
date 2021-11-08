#include<bits/stdc++.h>
using namespace std;
using i64= long long;
constexpr i64 mod=998244353;

i64 h[1010];
i64 dp[1010][40040];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    i64 ans=0;
    int pad=2e4;
    for(int i=1;i<=n;i++)
    {
        ans++;
        for(int j=1;j<i;j++)
        {
            auto t=h[i]-h[j];
            dp[i][t+pad]+=dp[j][t+pad]+1;
            dp[i][t+pad]%=mod;
            ans=(ans+dp[j][t+pad]+1)%mod;
        }
    }
    cout<<ans<<endl;
}
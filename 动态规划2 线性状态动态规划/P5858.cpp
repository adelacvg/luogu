#include<bits/stdc++.h>
using namespace std;
using i64=long long;
constexpr int maxn=5e3+10;

i64 a[maxn];
i64 dp[maxn][maxn];
int main()
{
    int n,w,s;
    cin>>n>>w>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j]=-1e15;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        deque<pair<i64,i64>> v;
        v.emplace_back(dp[i-1][w],w);
        for(int j=w;j>=1;j--)
        {
            while(!v.empty()&&v.front().second>j-1+s)
                v.pop_front();
            while(!v.empty()&&v.back().first<dp[i-1][j-1])
                v.pop_back();
            v.emplace_back(dp[i-1][j-1],j-1);
            dp[i][j]=v.front().first+j*a[i];
        }
    }
    long long ans=-1e15;
    for(int i=0;i<=w;i++)
    {
        ans=max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
}
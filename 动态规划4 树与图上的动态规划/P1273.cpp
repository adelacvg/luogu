#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int n, m;
vector<pair<int, int>> e[3030];
int money[3030];
i64 dp[3030][3030];
int dfs(int x)
{
    if (x > n - m)
    {
        dp[x][1]=money[x];
        return 1;
    }
    int sm=0;
    int son=0;
    for(auto [a,c]:e[x])
    {
        son = dfs(a);
        sm+=son;
        for(int i=sm;i>=1;i--)
        {
            for(int j=1;j<=son;j++)
            {
                if(i-j>=0)
                {
                    dp[x][i] = max(
                        dp[x][i],
                        dp[x][i-j]+dp[a][j]-c);
                }
            }
        }
    }
    return sm;
}
int main()
{
    for(int i=0;i<3030;i++)
    {
        for(int j=0;j<3030;j++)
        {
            dp[i][j]=INT_MIN;
        }
    }
    cin >> n >> m;
    for (int i = 1; i <= n - m; i++)
    {
        int k, a, c;
        cin >> k;
        while (k--)
        {
            cin >> a >> c;
            e[i].emplace_back(a, c);
        }
    }
    for (int i = n - m + 1; i <= n; i++)
        cin >> money[i];
    for(int i=1;i<=n;i++)
        dp[i][0]=0;
    dfs(1);
    for(int i=m;i>=1;i--)
    {
        if(dp[1][i]>=0)
        {
            cout<<i<<endl;
            break;
        }
    }
}
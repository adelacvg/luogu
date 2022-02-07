#include <bits/stdc++.h>
using namespace std;

int a[6010];
int fa[6010];
int dp[6010][6010];
vector<int> e[6010];

void dfs(int x)
{
    dp[x][0] = 0;
    dp[x][1] = a[x];
    for (auto i : e[x])
    {
        dfs(i);
        dp[x][0] += max(dp[i][0], dp[i][1]);
        dp[x][1] += dp[i][0];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[y].emplace_back(x);
        fa[x] = y;
    }
    int root;
    for (int i = 1; i <= n; i++)
        if (!fa[i])
            root = i;
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
}
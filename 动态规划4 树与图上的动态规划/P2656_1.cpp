#include <bits/stdc++.h>
using namespace std;
const int N = 8e4 + 10, M = 2e5 + 10;
int n, m, t, cnt, tot, T, s, ans;
int head[N], dfn[N], low[N], vis[N];
int col[N], H[N], sum[N], dis[N], V[N];
struct edge
{
    int from, to, next, val, k;
} e[M], E[M];
stack<int> st;
queue<int> q;
void addedge(int u, int v, int w, int k)
{
    e[++t] = (edge){u, v, head[u], w, k};
    head[u] = t;
}
void add(int u, int v, int w)
{
    E[++T].to = v;
    E[T].next = H[u];
    E[T].val = w;
    H[u] = T;
}
void tarjan(int u)//tarjan缩点模板
{
    dfn[u] = low[u] = ++cnt;
    vis[u] = 1;
    st.push(u);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        tot++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            col[v] = tot;
            vis[v] = 0;
        } while (v != u);
    }
}
void spfa(int s)//spfa跑最长路
{
    memset(dis, -1, sizeof(dis));
    memset(V, 0, sizeof(V));
    dis[s] = sum[s];
    V[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        V[u] = 0;
        for (int i = H[u]; i; i = E[i].next)
        {
            int v = E[i].to, w = E[i].val;
            if (dis[v] < dis[u] + w + sum[v])
            {
                dis[v] = dis[u] + w + sum[v];
                if (!V[v])
                {
                    V[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    ifstream cin("P2656_4.in");
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        double k;
        cin>>x>>y>>z>>k;
        addedge(x, y, z, k * 10);//先让恢复系数乘10
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= m; i++)
    {
        int x = e[i].from, y = e[i].to, z = e[i].val, k = e[i].k;
        if (col[x] == col[y])
            while (z)//同一个强连通分量就统计蘑菇数
            {
                sum[col[x]] += z;
                z = z * k / 10;//再整除10
            }
        else
            add(col[x], col[y], z);//不是同一个强连通分量就建边
    }
    cout<<tot<<endl;
    cin>>s;
    s = col[s];
    spfa(s);
    for (int i = 1; i <= tot; i++)
        ans = max(ans, dis[i]);//终点是未知的，所以通过比较dis找到最长路
    cout<<ans<<endl;
    return 0;
}
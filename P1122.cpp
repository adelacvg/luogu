#include<bits/stdc++.h>
using namespace std;
int a[20000];
int dp[20000];
vector<int> e[20000];
void dfs(int x,int fa)
{
    dp[x]=a[x];
    for(auto i:e[x])
    {
        if(i!=fa)
        {
            dfs(i,x);
            dp[x]+=dp[i]>0?dp[i]:0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    dfs(1,0);
    cout<<*max_element(next(begin(dp),1),next(begin(dp),n));
}
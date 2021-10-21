#include<bits/stdc++.h>
using namespace std;
int mp[110][110];
int cnt[110][110];
int ans=0;
int dx[4]{-1,0,1, 0};
int dy[4]{ 0,1,0,-1};
int n,m;

void dfs(int x,int y)
{
    if(cnt[x][y])
        return;
    cnt[x][y]=1;
    for(int i=0;i<4;i++)
    {
        auto tx=x+dx[i];
        auto ty=y+dy[i];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&mp[tx][ty]<mp[x][y])
        {
            dfs(tx,ty);
            cnt[x][y]=max(cnt[x][y],cnt[tx][ty]+1);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dfs(i,j);
            ans=max(ans,cnt[i][j]);
        }
    }
    cout<<ans<<endl;
}
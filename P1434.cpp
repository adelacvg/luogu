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
    for(int i=0;i<4;i++)
    {
        auto tx=x+dx[i];
        auto ty=y+dy[i];

        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&mp[tx][ty]<mp[x][y]&&cnt[x][y]+1>cnt[tx][ty])
        {
            cnt[tx][ty]=cnt[x][y]+1;
            ans=max(ans,cnt[tx][ty]);
            dfs(tx,ty);
        }
    }
}

int main()
{
    cin>>n>>m;
    int stx=0,sty=0;
    int t=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]>t)
            {
                t=mp[i][j];
                stx=i;
                sty=j;
            }
        }
    }
    cnt[stx][sty]=1;
    dfs(stx,sty);
    cout<<ans<<endl;
}
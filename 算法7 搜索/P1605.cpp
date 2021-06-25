#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ma(10,vector<int>(10,0));
int ans;
vector<int> dx{1,0,-1,0};
vector<int> dy{0,1,0,-1};
int n,m,t;
int sx,sy,fx,fy;
void dfs(int x,int y)
{
    if(x==fx&&y==fy)
    {
        ans++;
        ma[fx][fy]=0;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!ma[tx][ty])
        {
            ma[tx][ty]=1;
            dfs(tx,ty);
            ma[tx][ty]=0;
        }
    }
}
int main()
{
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    int xx,yy;
    for(int i=0;i<t;i++)
    {
        cin>>xx>>yy;
        ma[xx][yy]=1;
    }
    ma[sx][sy]=1;
    dfs(sx,sy);
    cout<<ans<<endl;
}
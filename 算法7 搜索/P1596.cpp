#include<bits/stdc++.h>
using namespace std;
vector<int> dx{1,1,0,-1,-1,-1, 0, 1};
vector<int> dy{0,1,1, 1, 0,-1,-1,-1};
vector<vector<int>> vis(110,vector<int>(110,0));
vector<string> ma(110);
int n,m;

void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<8;i++)
    {
        auto tx=x+dx[i];
        auto ty=y+dy[i];
        if(tx>=0&&tx<n&&ty>=0&&
        ty<m&&ma[tx][ty]=='W'&&vis[tx][ty]==0)
            dfs(tx,ty);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>ma[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ma[i][j]=='W'&&!vis[i][j])
            {
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
}
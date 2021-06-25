#include<bits/stdc++.h>
using namespace std;
int n,m;
int sx,sy;
map<pair<int,int>,pair<int,int>> pm;
map<char,pair<int,int>> cm;
vector<vector<char>> ma(400,vector<char>(400));
vector<vector<int>> vis(400,vector<int>(400,0));
vector<int> dx{1,0,-1, 0};
vector<int> dy{0,1, 0,-1};
int ans=500;
void bfs(int x,int y)
{
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(x,y,0));

    while(!q.empty())
    {
        auto [xx,yy,dep]=q.front();
        if(ma[xx][yy]=='=')
        {
            ans=dep;
            return;
        }
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=xx+dx[i];
            int ty=yy+dy[i];
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&ma[tx][ty]!='#')
            {
                if(ma[tx][ty]>='A'&&ma[tx][ty]<='Z')
                {
                    // cout<<ma[tx][ty]<<endl;
                    // cout<<tx<<" "<<ty<<endl;
                    auto [ttx,tty]=pm[make_pair(tx,ty)];
                    tx=ttx,ty=tty;
                    q.push(make_tuple(tx,ty,dep+1));
                }
                else if(vis[tx][ty]==0)
                {
                    vis[tx][ty]++;
                    q.push(make_tuple(tx,ty,dep+1));
                }
            }
        }

    }

}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ma[i][j];
            if(ma[i][j]=='@')
            {
                sx=i;
                sy=j;
            }
            if(ma[i][j]>='A'&&ma[i][j]<='Z')
            {
                if(!cm.count(ma[i][j]))
                    cm[ma[i][j]]=make_pair(i,j);
                else
                {
                    pm[cm[ma[i][j]]]=make_pair(i,j);
                    pm[make_pair(i,j)]=cm[ma[i][j]];
                }
            }
        }
    }
    bfs(sx,sy);
    cout<<ans<<endl;
}
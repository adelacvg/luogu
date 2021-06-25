#include<bits/stdc++.h>
using namespace std;
bool bfs(int sx,int sy,int n,int m,
vector<vector<bool>>& ma)
{
    queue<tuple<int,int,int,int>> q;
    vector<vector<vector<int>>> vis(n,
    vector<vector<int>>(m,vector<int>(3)));
    q.emplace(make_tuple(sx,sy,sx,sy));
    vis[sx][sy][0]=1;
    vis[sx][sy][1]=sx;
    vis[sx][sy][2]=sy;
    vector<int> dx{-1,0,1, 0};
    vector<int> dy{ 0,1,0,-1};
    while(!q.empty())
    {
        auto [x,y,rx,ry]=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            auto tx=(x+dx[i]+n)%n;
            auto ty=(y+dy[i]+m)%m;
            auto rxt=rx+dx[i];
            auto ryt=ry+dy[i];
            if(ma[tx][ty])
            {
                if(!vis[tx][ty][0])
                {
                    vis[tx][ty]={1,rxt,ryt};
                    q.emplace(make_tuple(tx,ty,rxt,ryt));
                }
                else
                {
                    if(vis[tx][ty][1]!=rxt||vis[tx][ty][2]!=ryt)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    int n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m)
    {
        char c;
        vector<vector<bool>> ma(n+1,vector<bool>(m+1,0));
        int sx,sy;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>c;
                if(c!='#')
                    ma[i][j]=1;
                if(c=='S')
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        if(bfs(sx,sy,n,m,ma))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}
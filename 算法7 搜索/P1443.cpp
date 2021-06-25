#include<bits/stdc++.h>
using namespace std;
int ans[500][500];
int dx[10]{2,1,-1,-2,-2,-1, 1, 2};
int dy[10]{1,2, 2, 1,-1,-2,-2,-1};
void bfs(int n,int m,int x,int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        auto p=q.front();
        int x1=p.first,y1=p.second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            auto tx=x1+dx[i],ty=y1+dy[i];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m)
            {
                if(ans[x1][y1]+1<ans[tx][ty]||ans[tx][ty]==-1)
                {
                    ans[tx][ty]=ans[x1][y1]+1;
                    q.push(make_pair(tx,ty));
                }
            }
        }
    }
}

int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans[i][j]=-1;
        }
    }
    ans[x][y]=0;
    bfs(n,m,x,y);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<left<<setw(4)<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
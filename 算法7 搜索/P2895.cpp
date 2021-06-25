#include<bits/stdc++.h>
using namespace std;

vector<int> dx{1,0,-1, 0};
vector<int> dy{0,1, 0,-1};
vector<vector<int>> m(400,vector<int>(400,-1));
vector<vector<int>> ans(400,vector<int>(400,-1));
int main()
{
    int n;
    cin>>n;
    int tt=0;
    int xx,yy;
    for(int i=0;i<n;i++)
    {
        cin>>xx>>yy>>tt;
        if(m[xx][yy]==-1)
            m[xx][yy]=tt;
        else
            m[xx][yy]=min(m[xx][yy],tt);
        for(int i=0;i<4;i++)
        {
            auto tx=xx+dx[i];
            auto ty=yy+dy[i];
            if(tx>=0&&ty>=0)
            {
                if(m[tx][ty]==-1||tt<m[tx][ty])
                    m[tx][ty]=tt;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    ans[0][0]=0;
    int flag=0;
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        if(m[x][y]==-1)
        {
            flag=1;
            cout<<ans[x][y]<<endl;
            break;
        }
        for(int i=0;i<4;i++)
        {
            auto tx=x+dx[i];
            auto ty=y+dy[i];
            if(tx>=0&&ty>=0)
            {
                if(ans[tx][ty]==-1&&
                (ans[x][y]+1<m[tx][ty]||m[tx][ty]==-1))
                {
                    ans[tx][ty]=ans[x][y]+1;
                    q.push(make_pair(tx,ty));
                }
            }
        }
    }
    if(!flag)cout<<-1<<endl;
}
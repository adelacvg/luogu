#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> ma(40,vector<int>(40,0));
vector<int> dx{1,0,-1, 0};
vector<int> dy{0,1, 0,-1};

int dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(ma[tx][ty]==0)
            return 0;
        if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&ma[tx][ty]==1)
        {
            ma[tx][ty]=3;
            if(!dfs(tx,ty))
            {
                ma[tx][ty]=1;
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>ma[i][j];
            if(ma[i][j]==0)
                ma[i][j]=1;
            else if(ma[i][j]==1)
                ma[i][j]=2;
        }
    }
    int ans_x=0,ans_y=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ma[i][j]==1)
            {
                ma[i][j]=3;
                if(dfs(i,j))
                {
                    ans_x=i;
                    ans_y=j;
                    break;
                }
                else
                    ma[i][j]=1;
            }
        }
        if(ans_x&&ans_y)
            break;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ma[i][j]==1)
                cout<<0;
            else if(ma[i][j]==2)
                cout<<1;
            else if(ma[i][j]==3)
                cout<<2;
            cout<<" ";
        }
        cout<<endl;
    }
}
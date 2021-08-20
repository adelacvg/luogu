#include<bits/stdc++.h>
using namespace std;

int n;
int mp[10][10];
int ans[10][10];
int state[10][10][10];
bool vis[10][10];

void copy(int x)
{
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=7;j++)
        {
            state[x][i][j]=mp[i][j];
        }
    }
}
void update()
{
    for(int i=1;i<=5;i++)
    {
        int x=0;
        for(int j=1;j<=7;j++)
        {
            if(!mp[i][j])
                x++;
            else
            {
                if(!x)
                    continue;
                mp[i][j-x]=mp[i][j];
                mp[i][j]=0;
            }
        }
    }
}
bool remove()
{
    int flag=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(i-1>=1&&i+1<=5&&mp[i][j]==mp[i-1][j]&&
            mp[i][j]==mp[i+1][j]&&mp[i][j])
            {
                vis[i-1][j]=1;
                vis[i+1][j]=1;
                vis[i][j]=1;
                flag=1;
            }
            if(j-1>=1&&i+1<=7&&mp[i][j]==mp[i][j-1]&&
            mp[i][j]==mp[i][j+1]&&mp[i][j])
            {
                vis[i][j-1]=1;
                vis[i][j+1]=1;
                vis[i][j]=1;
                flag=1;
            }
        }
    }
    if(!flag)
        return 0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(vis[i][j])
            {
                vis[i][j]=0;
                mp[i][j]=0;
            }
        }
    }
    return 1;
}
void move(int i,int j,int x)
{
    swap(mp[i][j],mp[i+x][j]);
    update();
    while(remove())
        update();
}
bool check()
{
    for(int i=1;i<=5;i++)
    {
        if(mp[i][1])
            return 0;
    }
    return 1;
}

void dfs(int x)
{
    if(check())
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<'\n';
        }
        exit(0);
    }
    if(x==n+1)
        return;
    copy(x);
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(mp[i][j])
            {
                if(i+1<=5)
                {
                    move(i,j,1);
                    ans[x][1]=i-1;
                    ans[x][2]=j-1;
                    ans[x][3]=1;
                    dfs(x+1);
                    for(int i=1;i<=5;i++)
                    {
                        for(int j=1;j<=7;j++)
                        {
                            mp[i][j]=state[x][i][j];
                        }
                    }
                    ans[x][1]=-1;
                    ans[x][2]=-1;
                    ans[x][3]=-1;
                }
                if(i-1>=1&&mp[i-1][j]==0)
                {
                    move(i,j,-1);
                    ans[x][1]=i-1;
                    ans[x][2]=j-1;
                    ans[x][3]=-1;
                    dfs(x+1);
                    for(int i=1;i<=5;i++)
                    {
                        for(int j=1;j<=7;j++)
                        {
                            mp[i][j]=state[x][i][j];
                        }
                    }
                    ans[x][1]=-1;
                    ans[x][2]=-1;
                    ans[x][3]=-1;
                }
            }
        }
    }
}

int main()
{
    cin>>n;
    int x;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=8;j++)
        {
            cin>>x;
            if(x==0)
                break;
            mp[i][j]=x;
        }
    }
    memset(ans,-1,sizeof(ans));
    dfs(1);
    cout<<-1<<endl;
}
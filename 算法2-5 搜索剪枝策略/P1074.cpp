#include<bits/stdc++.h>
using namespace std;
constexpr int n=10;
int a[n][n],m[n][n],vis[3][n][n],b[82],maxn,flag;
struct Row
{
    int r,zero_cnt;
}row[n];

auto cmp=[](Row a,Row b)
{
    return a.zero_cnt<b.zero_cnt;
};

int getGrid(int x,int y)
{
    return (x-1)/3*3+(y-1)/3+1;
}
int getScore(int x,int y)
{
    for(int i=1;i<=5;i++)
    {
        if(x==i||y==i||x==10-i||y==10-i)
            return 5+i;
    }
    return 0;
}
int cal()
{
    int sum=0;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            sum+=m[i][j]*getScore(i,j);
        }
    }
    return sum;
}
void dfs(int xx)
{
    if(xx==82)
    {
        flag=1;
        maxn=max(maxn,cal());
        return;
    }
    int x=(b[xx]-1)/9+1;
    int y=(b[xx]-1)%9+1;
    if(!a[x][y])
    {
        for(int j=1;j<=9;j++)
        {
            int g=getGrid(x,y);
            if(!vis[0][x][j]&&!vis[1][y][j]&&!vis[2][g][j])
            {
                m[x][y]=j;
                vis[0][x][j]=1;
                vis[1][y][j]=1;
                vis[2][g][j]=1;
                dfs(xx+1);
                vis[0][x][j]=0;
                vis[1][y][j]=0;
                vis[2][g][j]=0;
            }
        }
    }
    else
        dfs(xx+1);
}
int main()
{
    for(int i=1;i<=9;i++)
    {
        int cnt=0;
        for(int j=1;j<=9;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
                cnt++;
            else
            {
                int v=a[i][j];
                int g=getGrid(i,j);
                m[i][j]=v;
                vis[0][i][v]=1;
                vis[1][j][v]=1;
                vis[2][g][v]=1;
            }
        }
        row[i].r=i;
        row[i].zero_cnt=cnt;
    }
    sort(row+1,row+10,cmp);
    int num=0;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            int x=row[i].r;
            int y=j;
            num++;
            b[num]=(x-1)*9+y;
        }
    }
    dfs(1);
    if(flag)
        cout<<maxn<<endl;
    else
        cout<<-1<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int r,c,k;
int ans=0;
vector<vector<char>> v(110,vector<char>(110,0));
vector<vector<bool>> flag(110,vector<bool>(110,0));
void dfs1(int x,int y)
{
    flag[x][y]=true;
    int len=1;
    int tx=x,ty=y;
    while(v[tx][ty+1]=='.'&&
        !flag[tx][ty+1]&&ty+1<=c)
    {
        flag[tx][ty+1]=1;
        len++;
        ty++;
    }
    if(len>=k)
        ans+=len-k+1;
}
void dfs2(int x,int y)
{
    flag[x][y]=true;
    int len=1;
    int tx=x,ty=y;
    while(v[tx+1][ty]=='.'&&
        !flag[tx+1][ty]&&tx+1<=r)
    {
        flag[tx+1][ty]=1;
        len++;
        tx++;
    }
    if(len>=k)
        ans+=len-k+1;
}

int main()
{
    cin>>r>>c>>k;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin>>v[i][j];
        }
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(!flag[i][j]&&v[i][j]=='.')
            {
                dfs1(i,j);
            }
        }
    }
    for(auto &i:flag) fill(begin(i),end(i),0);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(!flag[i][j]&&v[i][j]=='.')
            {
                dfs2(i,j);
            }
        }
    }
    if(k==1)ans/=2;
    cout<<ans<<endl;
}
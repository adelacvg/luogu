#include<bits/stdc++.h>
using namespace std;
vector<int> dx{1,1,0,-1,-1,-1, 0, 1};
vector<int> dy{0,1,1, 1, 0,-1,-1,-1};
int n;
vector<string> ma(110);
string s="yizhong";
vector<vector<int>> ans(110,vector<int>(110,0));

void dfs(int x,int y,int dir)
{
    int tx=x;
    int ty=y;
    int flag=1;
    for(int i=0;i<s.size();i++)
    {
        if(tx>=0&&tx<n&&ty>=0&&ty<n&&
        ma[tx][ty]==s[i])
        {
            tx+=dx[dir];
            ty+=dy[dir];
        }
        else
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        tx=x,ty=y;
        for(int i=0;i<s.size();i++)
        {
            ans[tx][ty]=1;
            tx+=dx[dir];
            ty+=dy[dir];
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ma[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ma[i][j]==s[0])
            {
                for(int dir=0;dir<8;dir++)
                    dfs(i,j,dir);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ans[i][j]==1)
                cout<<ma[i][j];
            else
                cout<<'*';
        }
        cout<<endl;
    }
}
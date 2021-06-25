#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> dm;
void dfs(vector<vector<char>>& ma,
int x,int y,int nxt,int dep,int cnt)
{
    ma[x][y]='o';
    if(!nxt)
        return;
    int txl=x,tyl=y,tnxt=nxt;
    if(!dm[make_pair(dep+1,2*cnt-1)])
    {
        while(tnxt--)
        {
            ma[--txl][--tyl]='/';
        }
        dfs(ma,--txl,--tyl,nxt/2,dep+1,2*cnt-1);
    }
    int txr=x,tyr=y;
    tnxt=nxt;
    if(!dm[make_pair(dep+1,2*cnt)])
    {
        while(tnxt--)
        {
            ma[--txr][++tyr]='\\';
        }
        dfs(ma,--txr,++tyr,nxt/2,dep+1,2*cnt);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        if(!m)
            cout<<"o";
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<" ";
        }
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        dm[make_pair(x,y)]=1;
    }
    int width=(1<<(n-2))*6-1;
    int height=(1<<(n-2))*3;
    int nxt=(height-1)/2;
    vector<vector<char>> ma(height,vector<char>(width,' '));
    dfs(ma,height-1,(width-1)/2,nxt,1,1);
    for(int i=height-1;i>=0;i--)
    {
        for(int j=0;j<width;j++)
        {
            cout<<ma[i][j];
        }
        cout<<endl;
    }
}
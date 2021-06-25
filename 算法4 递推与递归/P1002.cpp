#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,-2,-1,1,2, 2, 1,-1,-2};
const int dy[]={0, 1, 2,2,1,-1,-2,-2,-1};
unsigned long long dp[110][110];
int mp[110][110];
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    n+=2,m+=2,x+=2,y+=2;
    for(int i=0;i<9;i++)
    {
        mp[x+dx[i]][y+dy[i]]=1;
    }
    dp[1][2]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            if(!mp[i][j])
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
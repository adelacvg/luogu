#include<bits/stdc++.h>
using namespace std;
int bl[55][55][70];
int dis[55][55];

int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=1010;
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        dis[u][v]=1;
        bl[u][v][0]=1;
    }
    for(int i=1;i<=64;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int l=1;l<=n;l++)
                {
                    if(bl[j][k][i-1]&&bl[k][l][i-1])
                    {
                        bl[j][l][i]=1;
                        dis[j][l]=1;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    cout<<dis[1][n]<<endl;
}
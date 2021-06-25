#include<bits/stdc++.h>
using namespace std;

int main()
{
    int map[110][110]{0};
    int n,m,k;
    cin>>n>>m>>k;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        for(int j=x-1;j<=x+1;j++)
        {
            for(int k=y-1;k<=y+1;k++)
            {
                map[j][k]++;
            }
        }
        map[x-2][y]=1;
        map[x][y-2]=1;
        map[x+2][y]=1;
        map[x][y+2]=1;
    }
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        for(int j=x-2;j<=x+2;j++)
        {
            for(int k=y-2;k<=y+2;k++)
            {
                map[j][k]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!map[i][j])
                ans++;
        }
    }
    cout<<ans<<endl;
}
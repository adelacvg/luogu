#include<bits/stdc++.h>
using namespace std;
int cube[30][30][30];
int main()
{
    int w,x,h;
    cin>>w>>x>>h;
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=x;j++)
        {
            for(int k=1;k<=h;k++)
            {
                cube[i][j][k]=1;
            }
        }
    }
    int q;
    cin>>q;
    int x1,y1,z1,x2,y2,z2;
    for(int i=0;i<q;i++)
    {
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                for(int k=z1;k<=z2;k++)
                {
                    cube[i][j][k]--;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=x;j++)
        {
            for(int k=1;k<=h;k++)
            {
                if(cube[i][j][k]==1)
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
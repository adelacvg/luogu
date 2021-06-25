#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m[n+4][n+4]{0};
    int t=2;
    int x=1,y=1;
    int dir=1;
    m[x][y]=1;
    while(t<=n*n)
    {
        t--;
        m[x][y]=0;
        if(dir==1)
        {
            while(m[x][y]==0&&y<=n)
            {
                m[x][y]=t++;
                y++;
            }
            y--;
        }
        else if(dir==2)
        {
            while(m[x][y]==0&&x<=n)
            {
                m[x][y]=t++;
                x++;
            }
            x--;
        }
        else if(dir==3)
        {
            while(m[x][y]==0&&y>=1)
            {
                m[x][y]=t++;
                y--;
            }
            y++;
        }
        else
        {
            while(m[x][y]==0&&x>=1)
            {
                m[x][y]=t++;
                x--;
            }
            x++;
        }
        dir=dir%4+1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<setw(3)<<m[i][j];
        }
        cout<<endl;
    }
}
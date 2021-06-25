#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n+2,vector<char>(m+2,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='?')
                v[i][j]='0';
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i][j]=='*')
            {
                for(int u=i-1;u<=i+1;u++)
                {
                    for(int w=j-1;w<=j+1;w++)
                    {
                        if(v[u][w]!='*')
                            v[u][w]++;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
    }
}
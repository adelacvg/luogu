#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,c;
    cin>>n>>m>>c;
    vector<vector<int>> v(n+2,vector<int>(m+2,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
        }
    }
    int ans=INT_MIN;
    int x,y;
    for(int i=1;i+c-1<=n;i++)
    {
        for(int j=1;j+c-1<=m;j++)
        {
            auto t=v[i+c-1][j+c-1]-v[i-1][j+c-1]-v[i+c-1][j-1]+v[i-1][j-1];
            if(t>ans)
            {
                ans=t;
                x=i;
                y=j;
            }
        }
    }
    cout<<x<<" "<<y<<endl;
}
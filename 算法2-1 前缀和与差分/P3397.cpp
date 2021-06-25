#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int x1,y1,x2,y2;
    vector<vector<int>> mp(n+10,vector<int>(n+10,0));
    for(int i=0;i<m;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        mp[x1][y1]++;
        mp[x1][y2+1]--;
        mp[x2+1][y1]--;
        mp[x2+1][y2+1]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mp[i][j]+=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
            cout<<mp[i][j]<<" ";
        }
        cout<<'\n';
    }

}
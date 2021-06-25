#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;

int main()
{
    int t,k;
    cin>>t>>k;
    vector<vector<int>> ans(2010,vector<int>(2010,0));
    vector<vector<int>> nCm(2010,vector<int>(2010,0));
    nCm[0][0]=1;
    for(int x=1;x<=2000;x++)
    {
        nCm[x][0]=1;
        for(int i=x,j=1;i>=1&&j<=x;i--,j++)
        {
            nCm[x][j]=(nCm[x-1][j-1]+nCm[x-1][j])%k;
            ans[x][j]=ans[x-1][j]+
            ans[x][j-1]-ans[x-1][j-1];
            if(nCm[x][j]%k==0)
            {
                ans[x][j]++;
            }
        }
        ans[x][x+1]=ans[x][x];
    }
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        cout<<ans[n][min(m,n)]<<endl;
    }
    
}
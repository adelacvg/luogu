#include<bits/stdc++.h>
using namespace std;
vector<int> vis(110);
int main()
{
    int n,m;
    cin>>n>>m;
    int t=m;
    for(int i=0;i<n;i++)
    {
        while(vis[t])t=t%n+1;
        vis[t]=1;
        cout<<t<<" ";
        if(i==n-1)
            break;
        int cnt=1;
        while(cnt<m)
        {
            if(vis[t]==0)
            {
                cnt++;
            }
            t=t%n+1;
        }
    }
}
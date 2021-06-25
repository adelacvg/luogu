#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    vector<int> w(n+1),b(n+1),r(n+1);
    for(int i=1;i<=n;i++)
    {
        w[i]+=w[i-1];
        b[i]+=b[i-1];
        r[i]+=r[i-1];
        for(int j=0;j<m;j++)
        {
            if(v[i][j]!='W')
                w[i]++;
            if(v[i][j]!='B')
                b[i]++;
            if(v[i][j]!='R')
                r[i]++;
        }
    }
    int ans=2e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans=min(ans,w[i]+b[j]-b[i]+r[n]-r[j]);
        }
    }
    cout<<ans<<endl;
}
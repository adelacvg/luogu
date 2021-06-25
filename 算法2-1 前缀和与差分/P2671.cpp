#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> num(n+1),color(n+1);
    vector<vector<int>> cnt(n+1,vector<int>(2,0));
    vector<vector<int>> sm(n+1,vector<int>(2,0));
    const int mod=10007;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    for(int i=1;i<=n;i++)
    {
        cin>>color[i];
        cnt[color[i]][i&1]++;
        sm[color[i]][i&1]=(sm[color[i]][i&1]+num[i])%mod;
    }
    if(n<=2)
    {
        cout<<0<<endl;
        return 0;
    }
    unsigned long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+i*(num[i]*(cnt[color[i]][i&1]-2)%mod+sm[color[i]][i&1]))%mod;
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 dp[100010];
i64 c[10],d[10];
int n,s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=4;i++)
        cin>>c[i];
    cin>>n;
    dp[0]=1;
    for(i64 j=1;j<=4;j++)
    {
        for(i64 i=c[j];i<=100010;i++)
        {
            dp[i]+=dp[i-c[j]];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>d[1]>>d[2]>>d[3]>>d[4];
        cin>>s;
        i64 ans=0;
        for(int j=0;j<=((1<<4)-1);j++)
        {
            auto t=s;
            int cnt=0;
            for(int k=1;k<=4;k++)
            {
                if((j>>(k-1))&1)
                {
                    t-=c[k]*(d[k]+1);
                    cnt^=1;
                }
            }
            if(t<0)
                continue;
            if(!cnt)
                ans+=dp[t];
            else
                ans-=dp[t];
        }
        cout<<ans<<'\n';
    }

}
#include<bits/stdc++.h>
using namespace std;
i64 dp[100010];
i64 c[10],d[10];
int n,s;
using i64 = long long;
int main()
{
    for(int i=1;i<=4;i++)
        cin>>c[i];
    cin>>n;
    dp[0]=1;
    for(i64 j=1;j<=4;j++)
    {
        for(i64 i=c[i];i<=100010;i++)
        {
            dp[i]+=dp[i-c[j]];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>d[1]>>d[2]>>d[3]>>d[4];
        cin>>s;
        i64 ans=dp[s];
        for(int j=1;j<=4;j++)
            ans-=dp[s-(d[j]+1)*c[j]];
        for(int j=1;j<=4;j++)
            for(int k=j+1;k<=4;k++)
                ans+=dp[s-(d[j]+1)*c[j]-(d[k]+1)*c[k]];
        for(int j=1;j<=4;j++)
            for(int k=j+1;k<=4;k++)
                for(int l=k+1;k<=4;k++)
                    ans-=dp[s-
                    (d[j]+1)*c[j]-
                    (d[k]+1)*c[k]-
                    (d[l]+1)*c[l]];
        ans+=
    }

}
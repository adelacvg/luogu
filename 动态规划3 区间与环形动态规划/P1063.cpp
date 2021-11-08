#include<bits/stdc++.h>
using namespace std;


int a[300];
int dp[300][300];

int main()
{
    int ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[n+i]=a[i];
    }
    for(int len=1;len<=2*n;len++)
    {
        for(int i=1;i<=2*n;i++)
        {
            auto j=i+len;
            if(j>2*n)
                break;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=max(dp[i][j],
                dp[i][k]+dp[k+1][j]+
                a[i]*a[k+1]*a[j+1]);
            }
            if(len==n-1)
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int dp[110][110];

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    for(int len=0;len<=n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            auto j=i+len;
            if(i==j)
                dp[i][j]=1;
            else
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
                }
                else
                {
                    dp[i][j]=100000000;
                    for(int k=i;k<j;k++)
                    {
                        dp[i][j]=min(dp[i][j],
                        dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
    }
    cout<<dp[1][n];
}
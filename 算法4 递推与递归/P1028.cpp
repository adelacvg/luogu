#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> dp(1010,1);
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
        {
            dp[i]+=dp[j];
        }
    }
    cout<<dp[n]<<endl;
}
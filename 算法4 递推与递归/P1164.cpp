#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> dp(100010,0);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            dp[j]+=dp[j-v[i]];
        }
    }
    cout<<dp[m]<<endl;
}
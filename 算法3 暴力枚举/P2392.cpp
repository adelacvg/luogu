#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s(4);
    for(int i=0;i<4;i++)
        cin>>s[i];
    vector<int> v;
    int t;
    int ans=0;
    vector<int> dp(1210,0);
    int sum=0;
    for(int i=0;i<4;i++)
    {
        sum=0;
        v.clear();
        for(int j=0;j<s[i];j++)
        {
            cin>>t;
            v.emplace_back(t);
            sum+=t;
        }
        fill(begin(dp),end(dp),0);
        for(int u=0;u<s[i];u++)
        {
            for(int w=sum/2;w>=v[u];w--)
            {
                dp[w]=max(dp[w],dp[w-v[u]]+v[u]);
            }
        }
        ans+=sum-dp[sum/2];
    }
    cout<<ans<<endl;
}
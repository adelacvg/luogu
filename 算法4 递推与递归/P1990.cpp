#include<bits/stdc++.h>
using namespace std;
const long long mod=10000;

int main()
{
    int n;
    cin>>n;
    vector<long long> dp1(1000010,0);
    vector<long long> dp2(1000010,0);
    dp1[1]=1;
    dp1[2]=2;
    dp2[1]=1;
    dp2[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp1[i]=(dp1[i-1]+dp1[i-2]+2*dp2[i-2])%mod;
        dp2[i]=(dp1[i-1]+dp2[i-1])%mod;
    }
    cout<<dp1[n]<<endl;
}
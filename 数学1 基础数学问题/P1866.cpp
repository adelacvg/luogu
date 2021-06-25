#include<bits/stdc++.h>
using namespace std;
constexpr int mod=1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(begin(v),end(v));
    auto ans=1LL;
    int t=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans*(v[i]-t))%mod;
        t++;
    }
    cout<<ans<<endl;
}
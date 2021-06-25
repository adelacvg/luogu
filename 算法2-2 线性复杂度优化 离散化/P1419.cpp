#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int s,t;
    double ans=INT_MIN;
    cin>>n>>s>>t;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    vector<int> presum(n+1,0);
    for(int i=1;i<=n;i++)
    {
        presum[i]=presum[i-1]+v[i];
    }
    deque<int> q;
    q.push_back(0);

    auto k=[&](auto x,auto y)
    {
        return 1.0*(presum[x]-presum[y])/(x-y);
    };
    for(int i=s;i<=n;i++)
    {
        while(q.size()>=2&&(k(q[0],i)<k(q[1],i)||i-q[0]+1>t))
            q.pop_front();
        ans=max(ans,k(q[0],i));
        while(q.size()>=2&&k(q[q.size()-1],i-s+1)<k(q[q.size()-1],q[q.size()-2]))
            q.pop_back();
        q.push_back(i-s+1);
    }
    cout<<fixed<<setprecision(3)<<ans<<endl;
}
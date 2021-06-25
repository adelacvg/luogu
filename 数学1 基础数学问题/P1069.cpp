#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
vector<bool> flag(1e6,0);
void euler_sieve(int n)
{
    flag[1]=1;
    for(auto i=2ull;i<=n;i++)
    {
        if(!flag[i])
        {
            prime.emplace_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=n;j++)
        {
            flag[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}

int main()
{
    euler_sieve(100000);
    int n;
    int m1,m2;
    cin>>n>>m1>>m2;
    int ans=-1;
    unordered_map<int,int> mp;
    for(auto i:prime)
    {
        int t=0;
        while(m1%i==0)
        {
            m1/=i;
            t++;
        }
        if(t)
            mp[i]=t*m2;
    }
    // for(auto [p,pt]:mp)
    // {
    //     cout<<p<<" "<<pt<<endl;
    // }
    unsigned long long s;
    while(n--)
    {
        cin>>s;
        int f=1;
        int tans=0;
        for(auto [p,pt]:mp)
        {
            if(s%p)
            {
                f=0;
                break;
            }
            int t=0;
            while(s%p==0)
            {
                s/=p;
                t++;
            }
            if(t<pt)
            {
                tans=max(tans,(int)ceil(pt*1.0/t));
            }
        }
        if(f)
        {
            if(ans==-1)
                ans=tans;
            else
                ans=min(ans,tans);
        }
    }
    cout<<ans<<endl;
}
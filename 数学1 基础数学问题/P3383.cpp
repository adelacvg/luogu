#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
vector<bool> flag(1e8+10,0);
void sieve(unsigned long long n)
{
    for(auto i=2ull;i<=n;i++)
    {
        if(!flag[i])
            prime.emplace_back(i);
        for(auto j=0;j<prime.size()&&i*prime[j]<=n;j++)
        {
            flag[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    sieve(n);
    int x;
    while(q--)
    {
        cin>>x;
        cout<<prime[x-1]<<'\n';
    }
}
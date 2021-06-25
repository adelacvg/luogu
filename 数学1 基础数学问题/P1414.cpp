#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
vector<bool> flag(1e6+10,0);
void euler_sieve(int n)
{
    for(auto i=2ull;i<=n;i++)
    {
        if(!flag[i])
            prime.emplace_back(i);
        for(int j=0;j<prime.size()&&prime[j]*i<=n;j++)
        {
            flag[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    unordered_map<int,int> cnt;
    unordered_map<int,int> mx_num;

    for(auto i:v)
    {
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                cnt[j]++;
                if(mx_num[cnt[j]]<j)
                    mx_num[cnt[j]]=j;
                if(i/j!=j)
                {
                    cnt[i/j]++;
                    if(mx_num[cnt[i/j]]<i/j)
                        mx_num[cnt[i/j]]=i/j;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<mx_num[i]<<endl;
    }
}
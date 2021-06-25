#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int n)
{
    vector<bool> flag(100010,0);
    vector<int> v;
    for(long long i=2;i<=n;i++)
    {
        if(!flag[i])
            v.emplace_back(i);
        for(long long j=i*i;j<=n;j+=i)
        {
            flag[j]=1;
        }
    }
    return v;
}
int main()
{
    int n;
    cin>>n;
    auto p=sieve(n);
    int cnt=0;
    for(auto i:p)
    {
        if(n>=i)
        {
            cout<<i<<endl;
            n-=i;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
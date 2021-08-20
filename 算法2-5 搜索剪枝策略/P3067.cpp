#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
unordered_map<int,vector<int>> m;
bitset<1<<20> s;
void dfs1(int x,int sum,int t)
{
    if(x>=n/2)
    {
        m[sum].emplace_back(t);
        return;
    }
    dfs1(x+1,sum,t);
    dfs1(x+1,sum+a[x],t|(1<<x));
    dfs1(x+1,sum-a[x],t|(1<<x));
}
void dfs2(int x,int sum,int t)
{
    if(x>=n)
    {
        if(m.find(sum)==m.end())
            return;
        for(auto &i:m[sum])
        {
            s.set(t|i);
        }
        return;
    }
    dfs2(x+1,sum,t);
    dfs2(x+1,sum+a[x],t|(1<<x));
    dfs2(x+1,sum-a[x],t|(1<<x));
}

int main()
{
    cin>>n;
    copy_n(istream_iterator<int>(cin),n,
    back_inserter(a));
    dfs1(0,0,0);
    dfs2(n/2,0,0);
    int ans=0;
    for(int i=1;i<1<<n;i++)
        ans+=s[i];
    cout<<ans<<endl;
}
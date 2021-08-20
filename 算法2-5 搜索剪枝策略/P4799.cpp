#include<bits/stdc++.h>
using namespace std;
using i64=long long;
i64 n,m;
vector<i64> price;
vector<i64> lsum,rsum;
void dfs1(i64 x, i64 sum)
{
    if(x>=n/2)
    {
        lsum.emplace_back(sum);
        return;
    }
    dfs1(x+1, sum);
    dfs1(x+1, sum+price[x]);
}
void dfs2(i64 x, i64 sum)
{
    if(x>=n)
    {
        rsum.emplace_back(sum);
        return;
    }
    dfs2(x+1, sum);
    dfs2(x+1, sum+price[x]);
}

int main()
{
    cin>>n>>m;
    copy_n(istream_iterator<i64>(cin),n,
    back_inserter(price));
    dfs1(0,0);
    dfs2(n/2,0);
    sort(begin(lsum),end(lsum));
    i64 ans=0;
    for(auto i:rsum)
    {
        ans+=distance(begin(lsum),
        upper_bound(begin(lsum),end(lsum),m-i));
    }
    cout<<ans<<endl;
}
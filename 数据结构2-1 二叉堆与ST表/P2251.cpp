#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a;
    copy_n(istream_iterator<int>(cin),n,
    back_inserter(a));
    deque<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        while(!q.empty()&&q.front().second<=i-m)
            q.pop_front();
        while(!q.empty()&&a[i]<=q.back().first)
            q.pop_back();
        q.emplace_back(make_pair(a[i],i));
        if(i>=m-1)
        cout<<q.front().first<<'\n';
    }
}
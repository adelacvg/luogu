#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    copy_n(istream_iterator<int>(std::cin),
    7,
    back_inserter(v));
    sort(begin(v),end(v));
    vector<int> t,s;
    vector<int> ans(10);
    for(int i=0;i<n;i++)
    {
        t.clear();
        s.clear();
        copy_n(istream_iterator<int>(std::cin),
        7,
        back_inserter(t));
        sort(begin(t),end(t));
        set_intersection(begin(v),end(v),
        begin(t),end(t),
        back_inserter(s));
        ans[s.size()]++;
    }
    for(int i=7;i>=1;i--)
    {
        cout<<ans[i]<<" ";
    }
}
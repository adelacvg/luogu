#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    copy_n(istream_iterator<int>(cin),
    m,
    back_inserter(v));
    sort(begin(v),end(v));
    for(auto i:v)
    {
        cout<<i<<" ";
    }
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(begin(v),end(v));
    vector<int> w;
    vector<int> sz;
    for(int i=0;i<n;i++)
    {
        auto p=upper_bound(begin(w),end(w),v[i]);
        if(w.empty()||*(p-1)!=v[i])
        {
            w.push_back(v[i]+1);
            sz.push_back(1);
        }
        else
        {
            (*(p-1))++;
            sz[distance(begin(w),p-1)]++;
        }
    }
    auto me=min_element(begin(sz),end(sz));
    cout<<sz[distance(sz.begin(),me)];
}
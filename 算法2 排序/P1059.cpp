#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        v.emplace_back(t);
    }
    sort(begin(v),end(v));
    v.erase(unique(v.begin(),v.end()),v.end());
    cout<<v.size()<<endl;
    for(auto i:v)
        cout<<i<<" ";
}
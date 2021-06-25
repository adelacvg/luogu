#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<m;i++)
        next_permutation(begin(v),end(v));
    for(auto i:v)
        cout<<i<<" ";
}
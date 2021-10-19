#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.emplace_back(x);
    }
    if(prev_permutation(begin(v),end(v)))
        for(auto i:v)
            cout<<i<<" ";
    else
        cout<<"ERROR"<<'\n';
}
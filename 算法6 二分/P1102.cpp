#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c;
    cin>>n>>c;
    map<int,int> m;
    vector<int> v(n);
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        m[v[i]]++;
    }
    long long ans=0;
    for(auto i:v)
    {
        ans+=m[i+c];
    }
    cout<<ans<<endl;
}
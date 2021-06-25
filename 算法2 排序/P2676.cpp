#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,h;
    cin>>n>>h;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(begin(v),end(v));
    int t=n-1;
    int ans=0;
    while(h>0)
    {
        h-=v[t--];
        ans++;
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n+2,0);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    int ans=0;
    for(int i=1;i<=n+1;i++)
    {
        if(v[i]<v[i-1])
            ans+=v[i-1]-v[i];
    }
    cout<<ans<<endl;
}
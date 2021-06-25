#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int x;
    int ans=0;
    while(n--)
    {
        cin>>x;
        ans^=x;
    }
    cout<<ans<<endl;
}
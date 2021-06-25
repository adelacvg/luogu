#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,t,s;
    cin>>m>>t>>s;
    int ans;
    if(t==0) ans=0;
    else ans=max(0,(int)(m-ceil(s*1.0/t)));
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int n;
    cin>>n;
    unsigned int ans=(n>>16)+((n&0xffff)<<16);
    cout<<ans<<endl;
}
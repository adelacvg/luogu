#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m;
    cin>>m;
    int t=0;
    for(auto i:s)
    {
        if(isdigit(i))
        {
            t=t*n+i-'0';
        }
        else
        {
            t=t*n+i-'A'+10;
        }
    }
    stringstream ss;
    while(t)
    {
        auto tt=t%m;
        t/=m;
        if(tt<10)
            ss<<tt;
        else
            ss<<char(tt-10+'A');
    }
    string ans=ss.str();
    reverse(begin(ans),end(ans));
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int r;
    cin>>n>>r;
    cout<<n<<"=";
    stringstream ss;
    while(n)
    {
        auto t=n%r;
        if(t<0)
        {
            t-=r;
            n+=r;
        }
        n/=r;
        if(t>=10)
            ss<<char(t-10+'A');
        else
            ss<<t;
    }
    string ans=ss.str();
    reverse(begin(ans),end(ans));
    cout<<ans;
    cout<<"(base"<<r<<")"<<endl;
}
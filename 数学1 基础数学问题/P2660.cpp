#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;

int main()
{
    i64 x,y;
    cin>>x>>y;
    i64 ans=0;
    while(x&&y)
    {
        auto l=min(x,y);
        auto r=max(x,y);
        if(l==r)
        {
            ans+=4*l;
            break;
        }
        else
        {
            ans+=4*(r/l)*l;
            r%=l;
        }
        x=l,y=r;
    }
    cout<<ans<<endl;
}
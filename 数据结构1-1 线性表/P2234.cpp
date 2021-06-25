#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    multiset<int> s;
    s.insert(INT_MIN);
    s.insert(INT_MAX);
    int x;
    cin>>x;
    long long ans=x;
    s.insert(x);
    n--;
    while(n--)
    {
        cin>>x;
        auto i=s.insert(x);
        auto l=--i;
        auto r=++++i;
        if(*(l)==INT_MIN) ans+=abs(x-*(r));
        else if(*(r)==INT_MAX) ans+=abs(x-*(l));
        else
            ans+=min(abs(x-*(r)),abs(x-*(l)));
    }
    cout<<ans<<endl;
}
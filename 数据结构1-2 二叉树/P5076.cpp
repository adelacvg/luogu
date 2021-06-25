#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int q;
    long long x;
    multiset<long long> s;
    s.insert(-2147483647);
    s.insert(2147483647);
    while(n--)
    {
        cin>>q>>x;
        if(q==1)
        {
            auto i=s.lower_bound(x);
            cout<<distance(begin(s),i)<<endl;
        }
        else if(q==2)
        {
            auto p=begin(s);
            advance(p,x);
            cout<<*p<<endl;
        }
        else if(q==3)
        {
            auto i=s.lower_bound(x);
            cout<<*(--i)<<endl;
        }
        else if(q==4)
        {
            auto i=s.upper_bound(x);
            cout<<*i<<endl;
        }
        else
        {
            s.insert(x);
        }
    }
}
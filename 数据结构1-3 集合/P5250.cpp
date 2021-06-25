#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<int> s;
    s.emplace(-2e9);
    s.emplace(2e9);
    while(n--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            cin>>x;
            if(s.count(x))
            {
                cout<<"Already Exist"<<endl;
            }
            else
                s.emplace(x);
        }
        else
        {
            cin>>x;
            if(s.size()==2)
            {
                cout<<"Empty"<<endl;
            }
            else
            {
                auto p=s.lower_bound(x);
                if(*p==x)
                {
                    cout<<x<<endl;
                    s.erase(x);
                }
                else
                {
                    auto r=*p;
                    auto l=*(--p);
                    if(l==-2e9)
                    {
                        cout<<r<<endl;
                        s.erase(r);
                    }
                    else if(r==2e9)
                    {
                        cout<<l<<endl;
                        s.erase(l);
                    }
                    else if(x-l<=r-x)
                    {
                        cout<<l<<endl;
                        s.erase(l);
                    }
                    else
                    {
                        cout<<r<<endl;
                        s.erase(r);
                    }
                }
            }
        }
    }
}
#include<bits/stdc++.h>
using namespace std;

priority_queue<int> ql;
priority_queue<int,vector<int>,greater<int>> qr;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    copy_n(istream_iterator<int>(cin),n,
    back_inserter(v));
    ql.push(v[0]);
    cout<<v[0]<<'\n';
    for(int i=1;;i+=2)
    {
        if(i+2>=n)
            break;
        int a=v[i],b=v[i+1];
        if(a>ql.top())
            qr.emplace(a);
        else
            ql.emplace(a);
        if(b>ql.top())
            qr.emplace(b);
        else
            ql.emplace(b);
        while(abs(int(ql.size()-qr.size()))>1)
        {
            if(ql.size()>qr.size())
            {
                auto t=ql.top();
                ql.pop();
                qr.emplace(t);
            }
            else
            {
                auto t=qr.top();
                qr.pop();
                ql.emplace(t);
            }
        }
        if(ql.size()>qr.size())
            cout<<ql.top()<<'\n';
        else
            cout<<qr.top()<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int a;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        auto p=lower_bound(begin(v),end(v),a);
        if(p==end(v)||(*p)!=a)
        {
            cout<<-1<<" ";
        }
        else
        {
            cout<<distance(begin(v),p)+1<<" ";
        }
    }
}
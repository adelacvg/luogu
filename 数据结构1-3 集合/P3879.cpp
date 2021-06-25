#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<set<string>> v(n+1);
    for(int i=1;i<=n;i++)
    {
        int l;
        cin>>l;
        string s;
        while(l--)
        {
            cin>>s;
            if(v[i].count(s))
                continue;
            else
                v[i].emplace(s);
        }
    }
    int m;
    cin>>m;
    while(m--)
    {
        string s;
        cin>>s;
        for(int i=1;i<=n;i++)
        {
            if(v[i].count(s))
            {
                cout<<i<<" ";
            }
        }
        cout<<'\n';
    }
}
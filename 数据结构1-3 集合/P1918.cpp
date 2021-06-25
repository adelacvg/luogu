#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int> m;
    int t;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        m[t]=i;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(m.count(x))
        {
            cout<<m[x]<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    stack<int> s;
    vector<int> r(n+1);
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&v[s.top()]<=v[i])
            s.pop();
        if(!s.empty())
            r[i]=s.top();
        else
            r[i]=n+1;
        s.push(i);
    }
    int mx=0;
    int id=0;
    for(int i=1;i<=k;i++)
    {
        if(v[i]>mx)
        {
            mx=v[i];
            id=i;
        }
    }
    for(int i=k;i<=n;i++)
    {
        if(id>=i-k+1&&id<=i&&r[id]>i)
        {
            cout<<mx<<'\n';
        }
        else
        {
            mx=v[i-k+1];
            id=i-k+1;
            while(r[id]<=i)
            {
                mx=v[r[id]];
                id=r[id];
            }
            cout<<mx<<'\n';
        }
    }
}
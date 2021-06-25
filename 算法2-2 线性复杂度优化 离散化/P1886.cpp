#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<long long> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    stack<int> s;
    vector<int> r(n+1);//first right bigger
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
    stack<int> s1;
    vector<int> r1(n+1);//first right smaller
    for(int i=n;i>=1;i--)
    {
        while(!s1.empty()&&v[s1.top()]>=v[i])
            s1.pop();
        if(!s1.empty())
            r1[i]=s1.top();
        else
            r1[i]=n+1;
        s1.push(i);
    }
    long long mx=INT64_MIN;
    long long mn=INT64_MAX;
    int id=0;
    int id1=0;
    for(int i=1;i<=k;i++)
    {
        if(v[i]>mx)
        {
            mx=v[i];
            id=i;
        }
        if(v[i]<mn)
        {
            mn=v[i];
            id1=i;
        }
    }
    for(int i=k;i<=n;i++)
    {
        if(id1>=i-k+1&&id1<=i&&r1[id1]>i)
        {
            cout<<mn<<' ';
        }
        else
        {
            mn=v[i-k+1];
            id1=i-k+1;
            while(r1[id1]<=i)
            {
                mn=v[r1[id1]];
                id1=r1[id1];
            }
            cout<<mn<<' ';
        }
    }
    cout<<'\n';
    for(int i=k;i<=n;i++)
    {
        if(id>=i-k+1&&id<=i&&r[id]>i)
        {
            cout<<mx<<' ';
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
            cout<<mx<<' ';
        }
    }
}
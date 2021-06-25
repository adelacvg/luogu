#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n,k;
    cin>>n>>k;
    vector<i64> v(n);
    i64 sm=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>v[i];
        sm+=v[i];
    }
    i64 mx=0;
    for(int i=0;i<n-1&&i<k;i++)
    {
        mx+=v[i];
    }
    i64 ts=mx;
    int j=0;
    int i=k;
    while(i<n-1)
    {
        ts+=v[i];
        ts-=v[j];
        i++;
        j++;
        mx=max(mx,ts);
    }
    cout<<sm-mx<<endl;
}
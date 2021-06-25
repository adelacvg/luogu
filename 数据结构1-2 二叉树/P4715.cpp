#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(1<<n);
    map<int,int> m;
    for(int i=0;i<(1<<n);i++)
    {
        cin>>v[i];
        m[v[i]]=i+1;
    }
    sort(begin(v),begin(v)+(1<<(n-1)));
    sort(begin(v)+(1<<(n-1)),end(v));
    cout<<m[min(v[(1<<(n-1))-1],v[(1<<n)-1])]<<endl;
}
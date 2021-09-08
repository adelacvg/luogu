#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    sort(begin(a),end(a));
    sort(begin(b),end(b));
    using t3=tuple<int,int,int>;
    priority_queue<t3,vector<t3>,greater<t3>> q;
    for(int i=0;i<n;i++)
    {
        q.emplace(b[i]+a[0],0,i);
    }
    while(n--)
    {
        auto [sum,i,j]=q.top();
        q.pop();
        cout<<sum<<" ";
        q.emplace(a[i+1]+b[j],i+1,j);
    }
}
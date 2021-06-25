#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> q;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        q.push(x);
    }
    long long ans=0;
    int a,b;
    if(n==1)
        ans=q.top();
    while(q.size()!=1)
    {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        ans+=a+b;
        q.push(a+b);
    }
    cout<<ans<<endl;
}
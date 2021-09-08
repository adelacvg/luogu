#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n),c(n);
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> q;
    vector<int> p(n,2);
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        q.emplace(make_pair(a[i]+b[i]+c[i],i));
    }
    while(m--)
    {
        cout<<q.top().first<<" ";
        auto i=q.top().second;
        q.pop();
        q.emplace(make_pair(
            a[i]*p[i]*p[i]+b[i]*p[i]+c[i],i));
        p[i]++;
    }
}
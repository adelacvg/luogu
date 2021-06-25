#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    deque<int> q;
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&q.front()<i-k+1)
            q.pop_front();
        while(!q.empty()&&v[q.back()]>=v[i])
            q.pop_back();
        q.push_back(i);
        if(i>=k)
        cout<<v[q.front()]<<' ';
    }
    cout<<'\n';
    deque<int> q1;
    for(int i=1;i<=n;i++)
    {
        while(!q1.empty()&&q1.front()<i-k+1)
            q1.pop_front();
        while(!q1.empty()&&v[q1.back()]<=v[i])
            q1.pop_back();
        q1.push_back(i);
        if(i>=k)
        cout<<v[q1.front()]<<' ';
    }
}
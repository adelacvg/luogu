#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> a(m);
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    vector<int> flag(2e5+10,0);
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        flag[x]++;
    }
    priority_queue<int,
    vector<int>,greater<int>> q1;
    priority_queue<int> q2;
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(!q2.empty())
            q2.emplace(a[i]);
        else
            q1.emplace(a[i]);
        if(q2.size()>cnt)
        {
            q1.emplace(q2.top());
            q2.pop();
        }
        while(flag[i+1])
        {
            flag[i+1]--;
            cout<<q1.top()<<'\n';
            q2.emplace(q1.top());
            cnt++;
            q1.pop();
        }
    }
}
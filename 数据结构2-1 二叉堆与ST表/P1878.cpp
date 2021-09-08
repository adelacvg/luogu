#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    vector<int> v(n+2);
    vector<int> l(n+2),r(n+2);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        l[i]=i-1;
        r[i]=i+1;
    }
    priority_queue<tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>>> q;
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i+1])
            q.emplace(abs(v[i]-v[i+1]),i,i+1);
    }
    stringstream ans;
    int cnt=0;
    while(!q.empty())
    {
        auto i=get<1>(q.top());
        auto j=get<2>(q.top());
        if(j!=r[i]||i!=l[j])
        {
            q.pop();
            continue;
        }
        q.pop();
        cnt++;
        ans<<i<<" "<<j<<'\n';
        auto tl=l[i];
        auto tr=r[j];
        r[tl]=tr;
        l[tr]=tl;
        if(tl>=1&&tl<=n&&tr>=1&&tr<=n&&s[tl]!=s[tr])
            q.emplace(abs(v[tl]-v[tr]),tl,tr);
    }
    cout<<cnt<<'\n';
    cout<<ans.str();
}
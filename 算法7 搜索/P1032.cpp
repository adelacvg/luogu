#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string a,b;
vector<string> v1,v2;
map<string,int> m;
int ans=11;
void bfs(string s,int dep)
{
    queue<pair<string,int>> q;
    q.push(make_pair(s,dep));
    while(!q.empty())
    {
        auto [ss,dept]=q.front();
        q.pop();
        if(m[ss])
            continue;
        m[ss]=1;
        if(dept>10)
            return;
        if(ss==s2)
        {
            ans=min(ans,dept);
            return;
        }
        for(int i=0;i<v1.size();i++)
        {
            auto st=begin(ss);
            auto t=begin(ss);
            while((t=search(st,end(ss),
            boyer_moore_searcher(begin(v1[i]),end(v1[i]))))!=ss.end())
            {
                int tt=t-begin(ss);
                auto ts=ss.substr(0,tt)+v2[i]+
                ss.substr(tt+v1[i].size(),ss.size()-tt-v1[i].size());
                q.push(make_pair(ts,dept+1));
                st=next(t,1);
            }
        }
    }
}

int main()
{
    cin>>s1>>s2;
    while(cin>>a>>b)
    {
        v1.push_back(a);
        v2.push_back(b);
    }
    bfs(s1,0);
    if(ans!=11)
        cout<<ans<<endl;
    else
        cout<<"NO ANSWER!"<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int count_s(string &s,string str)
{
    auto res=search(s.begin(),s.end(),
    boyer_moore_searcher(str.begin(),str.end()));
    int cnt=0;
    if(res!=s.end())
    {
        cnt++;
        for(int i=res-s.begin();
        i<res-s.begin()+str.size();i++)
            s[i]='.';
    }
    while(res!=s.end())
    {
        res=search(res+str.size(),s.end(),
        boyer_moore_searcher(str.begin(),str.end()));
        if(res!=s.end())
        {
            cnt++;
            for(int i=res-s.begin();
            i<res-s.begin()+str.size();i++)
                s[i]='.';
        }
    }
    return cnt;
}
vector<string> sub_string(string s)
{
    vector<string> sub;
    for(int i=s.size();i>=1;i--)
    {
        for(int j=0;j+i<=s.size();j++)
        {
            sub.emplace_back(s.substr(j,i));
        }
    }
    return sub;
}
int main()
{
    string s;
    getline(cin,s);
    map<char,int> m;
    string boy="boy";
    string girl="girl";
    int ans=0;
    for(auto i:sub_string(boy))
    {
        // cout<<i<<endl;
        ans+=count_s(s,i);
    }
    cout<<ans<<endl;
    ans=0;
    for(auto i:sub_string(girl))
    {
        // cout<<i<<endl;
        ans+=count_s(s,i);
    }
    cout<<ans<<endl;
}
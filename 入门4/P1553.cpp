#include<bits/stdc++.h>
using namespace std;
void delsuffix(string& s)
{
    auto t=begin(s);
    if((t=find_if(rbegin(s),rend(s),
        [](char c){return c!='0';}).base())!=
        s.begin())
        s.erase(t,end(s));
}
void delprefix(string& s)
{
    auto t=begin(s);
    if((t=find_if(begin(s),end(s),
    [](char c){return c!='0';}))!=s.end())
    s.erase(s.begin(),t);
}
int main()
{
    string s;
    cin>>s;
    auto t=begin(s);
    string s1,s2;
    if((t=find(begin(s),end(s),'.'))!=end(s))
    {
        reverse(begin(s),t);
        reverse(t+1,end(s));
        s1=s.substr(0,t-begin(s));
        s2=s.substr(t-begin(s)+1,end(s)-t);
        delsuffix(s2);
        cout<<stoll(s1)<<"."<<s2<<endl;
    }
    else if((t=find(begin(s),end(s),'/'))!=end(s))
    {
        reverse(begin(s),t);
        reverse(t+1,end(s));
        s1=s.substr(0,t-begin(s));
        s2=s.substr(t-begin(s)+1,end(s)-t);
        cout<<stoll(s1)<<"/"<<stoll(s2)<<endl;
    }
    else if((t=find(begin(s),end(s),'%'))!=end(s))
    {
        reverse(begin(s),t);
        s1=s.substr(0,t-begin(s));
        delprefix(s1);
        cout<<s1<<"%"<<endl;
    }
    else
    {
        reverse(begin(s),end(s));
        delprefix(s);
        cout<<s<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,str;
    getline(cin,str);
    getline(cin,s);
    s=" "+s+" ";
    transform(next(begin(s)),end(s),next(begin(s)),
    [](char c){return tolower(c);});
    transform(begin(str),end(str),begin(str),
    [](char c){return tolower(c);});
    auto res=search(begin(s),end(s),
            std::boyer_moore_searcher(
                begin(str),end(str)));
    int ans=-1,dis;
    int cnt=0;
    if(res!=s.end())
    {
        dis=distance(begin(s),res);
        if(s[dis-1]==' '&&s[dis+str.size()]==' ')
        {
            ans=dis-1;
            cnt++;
        }
    }
    while(res!=s.end())
    {
        res=search(res+str.size(),end(s),
            std::boyer_moore_searcher(
                begin(str),end(str)));
        if(res!=s.end())
        {
            dis=distance(begin(s),res);
            if(s[dis-1]==' '&&s[dis+str.size()]==' ')
            {
                if(ans==-1) ans=dis-1;
                cnt++;
            }
        }
    }
    if(ans!=-1)
    {
        cout<<cnt<<" "<<ans<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
}
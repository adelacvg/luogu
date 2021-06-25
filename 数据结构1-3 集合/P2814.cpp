#include<bits/stdc++.h>
using namespace std;
string find_fa(string x,map<string,string>& fa)
{
    return x==fa[x]?x:fa[x]=find_fa(fa[x],fa);
}

int main()
{
    string s;
    string fa;
    map<string,string> m;
    while(cin>>s)
    {
        if(s[0]=='$')
            break;
        else if(s[0]=='#')
        {
            s=s.substr(1);
            fa=s;
            if(!m.count(s))
                m[s]=s;
        }
        else if(s[0]=='+')
        {
            s=s.substr(1);
            if(!m.count(s))
                m[s]=s;
            m[find_fa(s,m)]=find_fa(fa,m);
        }
        else
        {
            s=s.substr(1);
            cout<<s<<" "<<find_fa(s,m)<<endl;
        }
    }
}
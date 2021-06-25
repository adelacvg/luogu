#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s,str;
    cin>>s;
    int op,a,b;
    for(int i=0;i<n;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>str;
            s=s+str;
            cout<<s<<endl;
        }
        else if(op==2)
        {
            cin>>a>>b;
            s=s.substr(a,b);
            cout<<s<<endl;
        }
        else if(op==3)
        {
            cin>>a>>str;
            s=s.substr(0,a)+str+s.substr(a,s.size()-a);            
            cout<<s<<endl;
        }
        else
        {
            cin>>str;
            auto res=search(begin(s),end(s),
            std::boyer_moore_searcher(
                begin(str),end(str)));
            if(res!=s.end())
            {
                cout<<distance(begin(s),res)<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
        }
    }
}
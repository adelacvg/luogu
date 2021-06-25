#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    string sub,subsub;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-')
        {
            if(s[i-1]>=s[i+1])
            continue;
            else if(s[i+1]==s[i-1]+1)
            {
                s=s.substr(0,i)+
                s.substr(i+1,s.size()-i-1);
            }
            else if(isdigit(s[i-1])&&isdigit(s[i+1])||
            isalpha(s[i-1])&&isalpha(s[i+1]))
            {
                sub="";
                for(char c=s[i-1]+1;c<=s[i+1]-1;c++)
                {
                    sub+=string(p2,c);
                }
                if(p1==2)
                    transform(begin(sub),end(sub),begin(sub),
                    [](char c){
                        return toupper(c);
                    });
                if(p1==3)
                    sub=string(sub.size(),'*');
                if(p3==2)
                    reverse(begin(sub),end(sub));
                s=s.substr(0,i)+sub+
                s.substr(i+1,s.size()-i-1);
            }
        }
    }
    cout<<s<<endl;
}
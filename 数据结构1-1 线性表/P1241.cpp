#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<bool> match(s.size());
    for(int i=0;i<s.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(s[i]==')'&&s[j]=='('&&!match[j])
            {
                match[i]=1;match[j]=1;
                break;
            }
            else if(s[i]==']'&&s[j]=='['&&!match[j])
            {
                match[i]=1;match[j]=1;
                break;
            }
            else if(s[i]==')'&&s[j]=='[')
            {
                if(!match[j])
                    break;
            }
            else if(s[i]==']'&&s[j]=='(')
            {
                if(!match[j])
                    break;
            }
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(match[i])
            cout<<s[i];
        else
        {
            if(s[i]=='('||s[i]==')')
                cout<<"()";
            else
                cout<<"[]";
        }
    }
}
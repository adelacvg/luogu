#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<int> st;
    for(int i=0;i<s.size();i++)
    {
        int t=0,a,b;
        if(s[i]=='@')
            break;
        else if(s[i]=='.')
            continue;
        else if(s[i]=='+')
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(a+b);
        }
        else if(s[i]=='-')
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(b-a);
        }
        else if(s[i]=='*')
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(a*b);
        }
        else if(s[i]=='/')
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(b/a);
        }
        else
        {
            while(i<s.size()&&s[i]>='0'&&s[i]<='9')
            {
                t=t*10+s[i]-'0';
                i++;
            }
            st.push(t);
        }
    }
    cout<<st.top()<<endl;
}
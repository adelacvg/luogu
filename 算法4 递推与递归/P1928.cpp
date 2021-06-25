#include<bits/stdc++.h>
using namespace std;
string dfs(stringstream &s)
{
    string res;
    string st;
    int n;
    char c;
    while(s>>c)
    {
        if(c=='[')
        {
            s>>n;
            st=dfs(s);
            while(n--)
                res+=st;
        }
        else
        {
            if(c==']')
                return res;
            else
                res+=c;
        }
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    stringstream ss(s);
    cout<<dfs(ss)<<endl;
}
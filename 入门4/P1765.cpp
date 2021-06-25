#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char,int> m;
    int t=1;
    for(int i='a';i<='r';i++)
    {
        m[char(i)]=t;
        t=t%3+1;
    }
    m['s']=4;
    for(int i='t';i<='y';i++)
    {
        m[char(i)]=t;
        t=t%3+1;
    }
    m['z']=4;
    m[' ']=1;
    string s;
    getline(cin,s);
    int ans=0;
    for(auto i:s)
    {
        ans+=m[i];
    }
    cout<<ans<<endl;
}
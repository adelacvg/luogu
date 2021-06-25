#include<bits/stdc++.h>
using namespace std;
int main()
{
    char t;
    map<char,char> m{{'a','0'},{'b','0'},{'c','0'}};
    char a,b;
    while (cin>>a>>t>>t>>b>>t)
    {
        if(isdigit(b))
            m[a]=b;
        else
            m[a]=m[b];
    }
    cout<<m['a']<<" "<<m['b']<<" "<<m['c']<<endl;
}
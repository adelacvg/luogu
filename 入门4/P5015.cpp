#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    s.erase(remove(begin(s),end(s),' '),end(s));
    cout<<s.size()<<endl;
}
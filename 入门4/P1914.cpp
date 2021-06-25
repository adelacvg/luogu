#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    transform(begin(s),end(s),begin(s),
    [=](char c)->char{
        return 'a'+(c-'a'+n)%26;
    });
    cout<<s<<endl;
}
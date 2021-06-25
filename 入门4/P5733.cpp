#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    transform(begin(s),end(s),begin(s),
    [](char c){return toupper(c);});
    cout<<s<<endl;
}
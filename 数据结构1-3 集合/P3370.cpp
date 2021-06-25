#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<string> se;
    while(n--)
    {
        string s;
        cin>>s;
        se.emplace(s);
    }
    cout<<se.size()<<endl;
}
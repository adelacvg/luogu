#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bitset<32> m(n);
    string s=m.to_string();
    s.erase(0,s.find_first_not_of('0'));
    cout<<s.size()<<endl;
}
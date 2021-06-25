#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char,int> m;
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b)swap(a,b);
    if(b>c)swap(b,c);
    if(a>b)swap(a,b);
    m['A']=a;
    m['B']=b;
    m['C']=c;
    string s;
    cin>>s;
    transform(s.begin(),s.end(),
    ostream_iterator<int>(std::cout," "),
    [&](auto i){return m[i];});
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
map<tuple<int,int,int>,int> mem;
long long w(long long a,long long b,long long c)
{
    if(mem[make_tuple(a,b,c)])
        return mem[make_tuple(a,b,c)];
    if(a<=0||b<=0||c<=0)
        return 1;
    if(a>20||b>20||c>20)
        return w(20,20,20);
    return mem[make_tuple(a,b,c)]=
    w(a-1,b,c)+w(a-1,b-1,c)+
    w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main()
{
    long long a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a==-1&&b==-1&&c==-1)
            break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<
        w(a,b,c)<<endl;
    }
}
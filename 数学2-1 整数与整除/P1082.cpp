#include<bits/stdc++.h>
using namespace std;

template<class T>
void exgcd(T a,T b,T& x,T& y)
{
    if(b==0)
    {
        y=0;
        x=1;
        return;
    }
    exgcd(b,a%b,x,y);
    auto t=x;
    x=y;
    y=t-a/b*y;
    return;
}

int main()
{
    //ax-bk=1
    long long a,b;
    cin>>a>>b;
    long long x,y;
    exgcd(a,b,x,y);
    cout<<(x+b)%b<<endl;
}
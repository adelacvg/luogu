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
    long long x,y,m,n,L;
    cin>>x>>y>>m>>n>>L;
    long long a=n-m;
    long long b=x-y;
    if(a<0)
    {
        a=-a;
        b=-b;
    }
    //zL+kA=B
    auto ggcd = gcd(L,a);
    if(b%ggcd)
        cout<<"Impossible"<<'\n';
    else
    {
        b/=ggcd;
        long long x1,y1;
        exgcd(L/ggcd,a/ggcd,x1,y1);
        cout<<(y1*b+L/ggcd)%(L/ggcd)<<endl;
    }
}
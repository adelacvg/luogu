#include<bits/stdc++.h>
using namespace std;
using i64=long long;
int main()
{
    i64 a,b,c,d;
    char ch;
    char op;
    cin>>a>>ch>>b;
    auto tab=gcd(a,b);
    a/=tab;
    b/=tab;
    while(cin>>op>>c>>ch>>d)
    {
        auto tcd=gcd(c,d);
        c/=tcd;
        d/=tcd;
        i64 t=gcd(b,d);
        i64 den=b*d/t;
        i64 num1=a*d/t;
        i64 num2=c*b/t;
        i64 num=0;
        if(op=='+')
            num=num1+num2;
        else
            num=num1-num2;
        i64 t1=gcd(num,den);
        num/=t1;
        den/=t1;
        a=num;
        b=den;
    }
    if(a==0)
        cout<<0<<endl;
    else if(b!=1)
    {
        if(a<0||a>0&&b<0)
        {
            cout<<'-';
        }
        cout<<abs(a)<<'/'<<abs(b)<<endl;
    }
    else
    {
        cout<<a<<endl;
    }
}